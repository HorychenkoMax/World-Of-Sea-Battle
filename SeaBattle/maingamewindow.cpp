#include "maingamewindow.h"
#include "ui_maingamewindow.h"

MainGameWindow::MainGameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainGameWindow)
{
    ui->setupUi(this);
    setBackground();

    myTableScene = new MyTableScene();
    ui->myTable->setScene(myTableScene);

    enemyTableScene = new EnemyTableScene();
    ui->enemyTable->setScene(enemyTableScene);
}

MainGameWindow::~MainGameWindow()
{
    delete ui;
    delete myTableScene;
    delete enemyTableScene;
}

void MainGameWindow::setBackground()
{
    QPixmap background(":/resources/game_window_images/gameWindowBackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}
