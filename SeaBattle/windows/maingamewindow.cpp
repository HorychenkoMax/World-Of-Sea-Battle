#include "windows/maingamewindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(SocketClient *client, BattleModel *battleModel, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGameWindow)
    , battleModel(battleModel)
    , client(client)
    , isMyTurn(client->getIsMyTurn())
{
    ui->setupUi(this);
    setBackground();

    myTableScene = new MyTableScene();
    ui->myTable->setScene(myTableScene);
    myTableScene->drawBoats(battleModel->getBoats());

    enemyTableScene = new EnemyTableScene();
    ui->enemyTable->setScene(enemyTableScene);

    connect(client, SIGNAL(readFromOponent(const QString&)), this, SLOT(readFromOponent(const QString &)));
    //connect(client, SIGNAL(readFromOponent(QString)),this, SLOT(readFromOponent(QString)));
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
        //CellType result =  battleModel->attack(i,j);
        //client->send("result=" + QString::number((qint32)result));
        //isMyTurn = true;
        //ui->attack->setEnabled(true);
        CellType result = battleModel->attack(i,j);
        client->send("result=" + QString::number((qint32)result));
        isMyTurn = true;
        ui->attack->setEnabled(true);
    }
}

void MainGameWindow::on_attack_clicked()
{

    if(!isMyTurn) return;
    qint32 i = enemyTableScene->getCurrent_item_pos_i();
    qint32 j = enemyTableScene->getCurrent_item_pos_j();
    if(i == -1 || j == -1) return;
    client->send("attack=" + QString::number(i) + " " + QString::number(j));
    isMyTurn = false;
    ui->attack->setEnabled(isMyTurn);
}

