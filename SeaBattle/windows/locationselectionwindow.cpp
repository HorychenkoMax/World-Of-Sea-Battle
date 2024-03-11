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

    loadingWindow = new LoadingWindow([&](){client->disconnect();});

    connect(client, SIGNAL(oponentDisconnected()), this, SLOT(oponentDisconnected()));
    connect(client, SIGNAL(readFromOponent(const QString&)), this, SLOT(readFromOponent(const QString &)));
}

LocationSelectionWindow::~LocationSelectionWindow()
{
    delete ui;
    delete mainGameWindow;
    delete loadingWindow;
}

void LocationSelectionWindow::setBackground()
{
    QPixmap background(":/resources/game_window_images/gameWindowBackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}

void LocationSelectionWindow::afterConnection()
{
    QTimer::singleShot(2000, this, [this](){                                        //lambda expression
        loadingWindow->hide();
        disconnect(client, SIGNAL(oponentDisconnected()), this, SLOT(oponentDisconnected()));
        disconnect(client, SIGNAL(readFromOponent(const QString&)), this, SLOT(readFromOponent(const QString &)));
        BattleModel *battleModel = new BattleModel(locationSelectionScene->fromBooatItemToBoat(), locationSelectionScene->getCell_matrix());
        mainGameWindow = new MainGameWindow(client ,battleModel, parent);
        mainGameWindow->show();
        close();
    });
}

void LocationSelectionWindow::on_nextButton_clicked()
{
    ui->nextButton->setDisabled(true);
    ui->rotateButton->setDisabled(true);

    if(locationSelectionScene->isAllShipsOnBoard()){
        loadingWindow->show();
        if(oponentRedy){
            client->send("can start");
            afterConnection();
        }else {
            client->send("ready");
        }
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

void LocationSelectionWindow::readFromOponent(const QString &string)
{
    if(string == "ready"){
        oponentRedy = true;
    }else if(string == "can start"){
        afterConnection();
    }
}

