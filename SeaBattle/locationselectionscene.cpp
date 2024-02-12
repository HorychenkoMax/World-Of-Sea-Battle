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



    QPixmap four_ship_pixmap_four(":/resources/ships_images/old/four_battleship_cut/four_battleship-removebg_4.png");
    QGraphicsPixmapItem *four_ship_four = new QGraphicsPixmapItem(
        four_ship_pixmap_four.scaled(33, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    four_ship_four->setPos(33, 33);
    addItem(four_ship_four);

    QPixmap four_ship_pixmap_three(":/resources/ships_images/old/four_battleship_cut/four_battleship-removebg_3.png");
    QGraphicsPixmapItem *four_ship_three = new QGraphicsPixmapItem(
        four_ship_pixmap_three.scaled(33, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    four_ship_three->setPos(66, 33);
    addItem(four_ship_three);

    QPixmap four_ship_pixmap_two(":/resources/ships_images/old/four_battleship_cut/four_battleship-removebg_2.png");
    QGraphicsPixmapItem *four_ship_two = new QGraphicsPixmapItem(
        four_ship_pixmap_two.scaled(33, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    four_ship_two->setPos(99, 33);
    addItem(four_ship_two);

    QPixmap four_ship_pixmap_one(":/resources/ships_images/old/four_battleship_cut/four_battleship-removebg_1.png");
    QGraphicsPixmapItem *four_ship_one = new QGraphicsPixmapItem(
        four_ship_pixmap_one.scaled(33, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    four_ship_one->setPos(132, 33);
    addItem(four_ship_one);

}
