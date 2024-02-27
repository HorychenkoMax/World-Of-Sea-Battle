#include "windows/optionswindow.h"
#include "ui_optionswindow.h"

OptionsWindow::OptionsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OptionsWindow)
{
    ui->setupUi(this);
    setBackground();
}

OptionsWindow::~OptionsWindow()
{
    delete ui;
}

void OptionsWindow::setBackground()
{
    QPixmap background(":/resources/main_window_images/optionWindowBackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);
}

void OptionsWindow::init()
{
    ui->lineEditForMyHost->setText(ConnectionProperties::init()->getMy_host_id());
    ui->lineEditForOtherHost->setText(ConnectionProperties::init()->getOther_host_id());
    ui->spinBoxForMyPort->setValue(ConnectionProperties::init()->getMy_port());
    ui->spinBoxForOtherPort->setValue(ConnectionProperties::init()->getOther_port());
}

void OptionsWindow::on_saveBotton_clicked()
{
    ConnectionProperties::init()->setMy_host_id(ui->lineEditForMyHost->text());
    ConnectionProperties::init()->setOther_host_id(ui->lineEditForOtherHost->text());
    ConnectionProperties::init()->setMy_port(ui->spinBoxForMyPort->value());
    ConnectionProperties::init()->setOther_port(ui->spinBoxForOtherPort->value());
    ConnectionProperties::init()->saveInformation();
    close();
}


void OptionsWindow::on_cancelBotton_clicked()
{
    close();
}

