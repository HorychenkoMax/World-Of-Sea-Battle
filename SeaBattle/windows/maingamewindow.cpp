#include "windows/maingamewindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(SocketClient *client, BattleModel *battleModel, QWidget *parent)
    : QMainWindow(nullptr)
    , ui(new Ui::MainGameWindow)
    , parent(parent)
    , battleModel(battleModel)
    , client(client)
    ,isMyTurn(client->getIsMyTurn())
{
    ui->setupUi(this);
    setBackground();

    myTableScene = new MyTableScene();
    ui->myTable->setScene(myTableScene);
    myTableScene->drawBoats(battleModel->getBoats());

    enemyTableScene = new EnemyTableScene();
    ui->enemyTable->setScene(enemyTableScene);

    connect(client, SIGNAL(readFromOponent(const QString&)), this, SLOT(readFromOponent(const QString &)));
    connect(client, SIGNAL(oponentDisconnected()), this, SLOT(oponentDisconnected()));

    logModel = new GameLogeModel(ui->logs, ui->information);

    ui->logs->setText(isMyTurn ? "Now it`s your turn\n":"Enemy is taking their turn");
    logModel->writeCounter(0);

}

MainGameWindow::~MainGameWindow()
{
    delete ui;
    delete myTableScene;
    delete enemyTableScene;
    delete logModel;

}

void MainGameWindow::setBackground()
{
    QPixmap background(":/resources/game_window_images/gameWindowBackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}

bool MainGameWindow::isWin()
{
    return numberOfDestroyedBoat >= 10;
}

void MainGameWindow::disconnectClients()
{
    disconnect(client, SIGNAL(oponentDisconnected()), this, SLOT(oponentDisconnected()));
    disconnect(client, SIGNAL(readFromOponent(const QString&)), this, SLOT(readFromOponent(const QString &)));
    client->disconnectFromHost();
}

void MainGameWindow::openLastWindow()
{
    LastWindow *lastWindow = new LastWindow(parent);
    lastWindow->setText(isWin());
    lastWindow->show();
    close();
}


void MainGameWindow::readFromOponent(const QString &string)
{
    if(string.startsWith("attack=")){
        QString index = string.sliced(7);
        QStringList list = index.split(" ");
        if(list.size() != 2){
            qDebug() << "error index";
            return;
        }
        qint32 i = list[0].toInt();
        qint32 j = list[1].toInt();
        CellType result = battleModel->attack(i,j);
        if(result == CellType::ERROR){
            client->send("exist_status");
            return;
        }

        if(result == CellType::DESTROYED){
            Boat* boat = battleModel->getBoatByHisDeck(i,j);
            QString new_result = "destroyed=";
            new_result = new_result + QString::number(boat->getHeadRow()) + ":" + QString::number(boat->getHeadColumn())
                        + ":" + QString::number(boat->getSize()) + ":" + QString::number((qint32)boat->getDirection());
            client->send(new_result);

            myTableScene->drawEffect(i,j, result);

            logModel->writeGameLog(result, true, isMyTurn);

            return;
        }

        client->send("result=" + QString::number((qint32)result));
        myTableScene->drawEffect(i,j, result);

        if(result == CellType::MISS){
            isMyTurn = true;
            ui->attack->setEnabled(isMyTurn);
        }

        logModel->writeGameLog(result, true, isMyTurn);

    }else if(string.startsWith("result=")){
        CellType type = (CellType)string.sliced(7).toInt();
        enemyTableScene->drawEffect(current_i, current_j, type);
        if(type == CellType::HURT){
            isMyTurn = true;
            ui->attack->setEnabled(isMyTurn);
        }

        logModel->writeGameLog(type, false, isMyTurn);


    }else if(string.startsWith("exist_status")){
        isMyTurn = true;
        ui->attack->setEnabled(isMyTurn);

    }else if(string.startsWith("destroyed=")){
        QString info = string.sliced(10);
        QStringList list = info.split(":");

        enemyTableScene->drawDestroyed(list[0].toInt(), list[1].toInt(), list[2].toInt(), (Direction)list[3].toInt());

        numberOfDestroyedBoat++;
        isMyTurn = true;
        ui->attack->setEnabled(isMyTurn);

        logModel->writeGameLog(CellType::DESTROYED, false, isMyTurn);
        logModel->writeCounter(list[2].toInt());

        if(isWin()){
            client->send("Im win");
            disconnectClients();
            openLastWindow();
        }

    }else if(string.contains("Im win")){
        disconnectClients();
        openLastWindow();
    }
}

void MainGameWindow::on_attack_clicked()
{
    if(!isMyTurn) return;
    current_i = enemyTableScene->getCurrent_item_pos_i();
    current_j = enemyTableScene->getCurrent_item_pos_j();
    enemyTableScene->setStartPosition();
    if(current_i == -1 || current_j == -1) return;
    isMyTurn = false;
    ui->attack->setEnabled(isMyTurn);
    client->send("attack=" + QString::number(current_i) + " " + QString::number(current_j));
}

void MainGameWindow::oponentDisconnected()
{
    QMessageBox::critical(this, "System message", "Oponent Disconnected");
    parent->show();
    close();
}

