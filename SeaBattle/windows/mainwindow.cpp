#include "windows/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    optionsWindow = new OptionsWindow();

    setProgramView();

    player = new MediaPlayer();
    player->paly(MusicType::BACKGROUND_MUSIC);
    player->setLoops(-1);

    ConnectionProperties::init();
    connect(&server, SIGNAL(newClient(SocketClient*)), this, SLOT(newClient(SocketClient*)));

    client = new SocketClient();
    connect(client, SIGNAL(connectedToHost()), this, SLOT(connectedToHost()));

    loadingWindow = new LoadingWindow([&](){server.close(); enableAllBottoms();});

   /* player = new QMediaPlayer();
    output = new QAudioOutput();
    player->setAudioOutput(output);
    player->setSource(QUrl("qrc:/resources/music/Ignis(chosic.com).mp3"));
    output->setVolume(1);
    player->play();
    player->setLoops(-1);*/
}

MainWindow::~MainWindow()
{
    delete ui;
    if(locationSelectionWindow){
        delete locationSelectionWindow;
    }
    delete optionsWindow;
    delete client;
    delete loadingWindow;
    delete player;
}


void MainWindow::on_hostButton_clicked()
{
    if(ConnectionProperties::init()->corectInformationForHosting()){
        bool isSuccess = server.run(ConnectionProperties::init()->getMy_host_id(), ConnectionProperties::init()->getMy_port());
        if(isSuccess){
            loadingWindow->show();
            disableAllBottoms();
            return;
        }
    }

    QMessageBox::critical(this, "Invalid information", "You have provided valid host data(ip, port)");
    getOptionWindow();
}


void MainWindow::on_ConnectButton_clicked()
{
    if(ConnectionProperties::init()->corectInformationForConnection()){
        client->run(ConnectionProperties::init()->getOther_host_id(), ConnectionProperties::init()->getOther_port());
        loadingWindow->show();
        disableAllBottoms();
    }else {
        getOptionWindow();
    }
}


void MainWindow::on_changeSkinButton_clicked()
{
    qDebug() << "changeSkinButton";
}


void MainWindow::on_optionButton_clicked()
{
    getOptionWindow();
}

void MainWindow::newClientAfterWaiting(SocketClient *client)
{
    loadingWindow->hide();
    locationSelectionWindow = new LocationSelectionWindow(client, this);
    locationSelectionWindow->show();
    hide();
    enableAllBottoms();
}

void MainWindow::disableAllBottoms()
{
    ui->hostButton->setDisabled(true);
    ui->ConnectButton->setDisabled(true);
    ui->changeSkinButton->setDisabled(true);
    ui->optionButton->setDisabled(true);
}

void MainWindow::enableAllBottoms()
{
    ui->hostButton->setDisabled(false);
    ui->ConnectButton->setDisabled(false);
    ui->changeSkinButton->setDisabled(false);
    ui->optionButton->setDisabled(false);
}

void MainWindow::newClient(SocketClient *client)
{
    QTimer::singleShot(2000, this, [this, client](){newClientAfterWaiting(client);});  //lambda expression
}

void MainWindow::connectedToHost()
{
    QTimer::singleShot(2000, this, [this](){                                        //lambda expression
        loadingWindow->hide();
        locationSelectionWindow = new LocationSelectionWindow(client, this);
        locationSelectionWindow->show();
        hide();
        enableAllBottoms();
    });
}

void MainWindow::setProgramView()
{
    QPixmap background(BACKGROUND_PATH);
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    QApplication::setWindowIcon(QIcon(WINDOW_ICON_PATH));
    //setWindowIcon();
    setWindowTitle("World Of Sea Battle");
}

void MainWindow::getOptionWindow()
{
    optionsWindow->init();
    optionsWindow->setModal(true);
    optionsWindow->exec();
}



