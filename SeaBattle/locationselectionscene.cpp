#include "locationselectionscene.h"

LocationSelectionScene::LocationSelectionScene(QObject *parent)
    : BattlefieldScene{498, 365, parent}
{
    createBattlefield();
    drawShips();
}

void LocationSelectionScene::drawShips()
{
    QPixmap four_ship_pixmap(":/resources/ships_images/old/four_battleship-removebg.png");
    QGraphicsPixmapItem *four_ship = new QGraphicsPixmapItem(
        four_ship_pixmap.scaled(132, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    four_ship->setPos(363, 0);
    addItem(four_ship);

    QPixmap three_ship_pixmap(":/resources/ships_images/old/three_battleship-removebg.png");
    QGraphicsPixmapItem *three_ship = new QGraphicsPixmapItem(
        three_ship_pixmap.scaled(99, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    three_ship->setPos(363, 33);
    addItem(three_ship);

    QPixmap two_ship_pixmap(":/resources/ships_images/old/two_battleship-removebg.png");
    QGraphicsPixmapItem *two_ship = new QGraphicsPixmapItem(
        two_ship_pixmap.scaled(66, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    two_ship->setPos(363, 66);
    addItem(two_ship);

    QPixmap one_ship_pixmap(":/resources/ships_images/old/one_battleship-removebg.png");
    QGraphicsPixmapItem *one_ship = new QGraphicsPixmapItem(
        one_ship_pixmap.scaled(33, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    one_ship->setPos(363, 99);
    addItem(one_ship);
}
