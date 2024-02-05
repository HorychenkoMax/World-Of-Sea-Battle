#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainGameWindow = new MainGameWindow();
    optionsWindow = new OptionsWindow();

    setProgramView();

    ConnectionProperties::init();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete mainGameWindow;
    delete optionsWindow;
}


void MainWindow::on_hostButton_clicked()
{
    if(ConnectionProperties::init()->corectInformationForHosting()){
        mainGameWindow->show();
        hide();
    }else {
        getOptionWindow();
    }

}


void MainWindow::on_ConnectButton_clicked()
{
    if(ConnectionProperties::init()->corectInformationForConnection()){

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

void MainWindow::setProgramView()
{
    QPixmap background(BACKGROUND_PATH);
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    setWindowIcon(QIcon(WINDOW_ICON_PATH));
    setWindowTitle("World Of Sea Battle");
}

void MainWindow::getOptionWindow()
{
    optionsWindow->init();
    optionsWindow->setModal(true);
    optionsWindow->exec();
}

