#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    locationSelectionWindow = new LocationSelectionWindow();
    optionsWindow = new OptionsWindow();

    setProgramView();

    ConnectionProperties::init();
    connect(&server, SIGNAL(newClient(SocketClient)), this, SLOT(newClient(SocketClient)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete locationSelectionWindow;
    delete optionsWindow;
}


void MainWindow::on_hostButton_clicked()
{
    if(ConnectionProperties::init()->corectInformationForHosting()){
        server.run(ConnectionProperties::init()->getMy_host_id(), ConnectionProperties::init()->getMy_port());
        //locationSelectionWindow->show();
        //hide();
    }else {
        getOptionWindow();
    }

}


void MainWindow::on_ConnectButton_clicked()
{
    if(ConnectionProperties::init()->corectInformationForConnection()){
        client.run(ConnectionProperties::init()->getOther_host_id(), ConnectionProperties::init()->getOther_port());
        //locationSelectionWindow->show();
        //hide();
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

void MainWindow::newClient(SocketClient client)
{
    qDebug() << "main window take client";
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

