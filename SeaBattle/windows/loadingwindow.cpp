#include "loadingwindow.h"
#include "ui_loadingwindow.h"

LoadingWindow::LoadingWindow(Function func, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadingWindow)
    , func(func)
{
    ui->setupUi(this);
    setBackground();
    //loadingScene = new LoadingScene();
    //ui->graphicsView->setScene(loadingScene);
}

LoadingWindow::~LoadingWindow()
{
    delete ui;
    //delete loadingScene;
}

void LoadingWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    func();
}

void LoadingWindow::setBackground()
{
    QPixmap background(":/resources/main_window_images/mainWindowBackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, background);
    this->setPalette(palette);

    QMovie *movie = new QMovie(":/resources/gifs/gif.gif");
    //QLabel *processLabel = new QLabel(this);
    ui->gif_label->setMovie(movie);
    movie->start();
}
