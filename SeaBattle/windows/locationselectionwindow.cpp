#include "windows/locationselectionwindow.h"
#include "ui_locationselectionwindow.h"

LocationSelectionWindow::LocationSelectionWindow(SocketClient *client, QWidget *parent)
    : QMainWindow(nullptr)
    , ui(new Ui::LocationSelectionWindow)
    , client(client)
    , parent(parent)
{
    ui->setupUi(this);
    setBackground();

    locationSelectionScene = new LocationSelectionScene();
    ui->locationSelectionView->setScene(locationSelectionScene);

    connect(client, SIGNAL(oponentDisconnected()), this, SLOT(oponentDisconnected()));
}

LocationSelectionWindow::~LocationSelectionWindow()
{
    delete ui;
    delete mainGameWindow;
}

void LocationSelectionWindow::setBackground()
{
    QPixmap background(":/resources/game_window_images/gameWindowBackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}

void LocationSelectionWindow::on_nextButton_clicked()
{
    if(locationSelectionScene->isAllShipsOnBoard()){
        BattleModel *battleModel = new BattleModel(locationSelectionScene->fromBooatItemToBoat(), locationSelectionScene->getCell_matrix());
        mainGameWindow = new MainGameWindow(client ,battleModel, parent);
        mainGameWindow->show();
        close();
    }
}


void LocationSelectionWindow::on_rotateButton_clicked()
{
    locationSelectionScene->rotate();
}

void LocationSelectionWindow::oponentDisconnected()
{
    QMessageBox::critical(this, "System message", "Oponent Disconnected");
    parent->show();
    close();
}

