#include "lastwindow.h"
#include "ui_lastwindow.h"

LastWindow::LastWindow(QWidget *parent)
    : QWidget(nullptr)
    , ui(new Ui::LastWindow)
    , parent(parent)
{
    ui->setupUi(this);
    setBackground();
}

LastWindow::~LastWindow()
{
    delete ui;
}

void LastWindow::setText(bool isWin)
{
    if(isWin){
        ui->label->setText("Victory");
    }else {
        ui->label->setText("Defeat");
    }
}

void LastWindow::setBackground()
{
    QPixmap background(":/resources/main_window_images/mainWindowBackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}

void LastWindow::on_mainWindowButton_clicked()
{
    parent->show();
    close();
}

