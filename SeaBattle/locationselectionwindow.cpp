#include "locationselectionwindow.h"
#include "ui_locationselectionwindow.h"

LocationSelectionWindow::LocationSelectionWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LocationSelectionWindow)
{
    ui->setupUi(this);
    setBackground();

    locationSelectionScene = new LocationSelectionScene();
    ui->locationSelectionView->setScene(locationSelectionScene);
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
    BattleModel *battleModel = new BattleModel(locationSelectionScene->fromBooatItemToBoat(), locationSelectionScene->getCell_matrix());
    mainGameWindow = new MainGameWindow(battleModel);
    mainGameWindow->show();
    hide();
}


void LocationSelectionWindow::on_rotateButton_clicked()
{
    locationSelectionScene->rotate();
}

