#include "windows/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    optionsWindow = new OptionsWindow();

    setProgramView();

    ConnectionProperties::init();
    connect(&server, SIGNAL(newClient(SocketClient*)), this, SLOT(newClient(SocketClient*)));

    client = new SocketClient();
    connect(client, SIGNAL(connectedToHost()), this, SLOT(connectedToHost()));

    loadingWindow = new LoadingWindow();
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
}


void MainWindow::on_hostButton_clicked()
{
    if(ConnectionProperties::init()->corectInformationForHosting()){
        bool isSuccess = server.run(ConnectionProperties::init()->getMy_host_id(), ConnectionProperties::init()->getMy_port());
        if(isSuccess){
            loadingWindow->show();
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

void MainWindow::newClient(SocketClient *client)
{
    qDebug() << "connected";
    loadingWindow->hide();
    locationSelectionWindow = new LocationSelectionWindow(client, this);
    locationSelectionWindow->show();
    hide();
}

void MainWindow::connectedToHost()
{
    loadingWindow->hide();
    locationSelectionWindow = new LocationSelectionWindow(client, this);
    locationSelectionWindow->show();
    hide();
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

