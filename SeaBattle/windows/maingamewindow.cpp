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
}

MainGameWindow::~MainGameWindow()
{
    delete ui;
    delete myTableScene;
    delete enemyTableScene;
    delete client;

}

void MainGameWindow::setBackground()
{
    QPixmap background(":/resources/game_window_images/gameWindowBackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
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
        if(result != CellType::ERROR){
            client->send("result=" + QString::number((qint32)result));
            myTableScene->drawEffect(i,j, result);
            if(result == CellType::MISS){
                isMyTurn = true;
                ui->attack->setEnabled(isMyTurn);
            }
        }else{
            client->send("exist_status");
        }
    }else if(string.startsWith("result=")){
        CellType type = (CellType)string.sliced(7).toInt();
        enemyTableScene->drawEffect(current_i, current_j, type);
        if(type == CellType::HURT){
            isMyTurn = true;
            ui->attack->setEnabled(isMyTurn);
        }
    }else if(string.startsWith("exist_status")){
        isMyTurn = true;
        ui->attack->setEnabled(isMyTurn);
    }
}

void MainGameWindow::on_attack_clicked()
{
    if(!isMyTurn) return;
    current_i = enemyTableScene->getCurrent_item_pos_i();
    current_j = enemyTableScene->getCurrent_item_pos_j();
    enemyTableScene->setStartPosition();
    if(current_i == -1 || current_j == -1) return;
    client->send("attack=" + QString::number(current_i) + " " + QString::number(current_j));
    isMyTurn = false;
    ui->attack->setEnabled(isMyTurn);
}

void MainGameWindow::oponentDisconnected()
{
    QMessageBox::critical(this, "System message", "Oponent Disconnected");
    parent->show();
    close();
}

