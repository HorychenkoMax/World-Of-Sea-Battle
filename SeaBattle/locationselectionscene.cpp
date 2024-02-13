#include "locationselectionscene.h"

LocationSelectionScene::LocationSelectionScene(QObject *parent)
    : BattlefieldScene{498, 365, parent}
{
    createBattlefield();
    createShipsIkons();
    drawShips();
}

void LocationSelectionScene::rotate()
{
    if(direction == Direction::LEFT){
        direction = Direction::DOWN;
        rotate_angle = 90;
    }else if(direction == Direction::DOWN){
        direction = Direction::RIGHT;
        rotate_angle = 180;
    } else if(direction == Direction::RIGHT){
        direction = Direction::UP;
        rotate_angle = 270;
    } else if(direction == Direction::UP){
        direction = Direction::LEFT;
        rotate_angle = 0;
    }

    four_deck_ship->setRotation(rotate_angle);
    three_deck_ship->setRotation(rotate_angle);
    two_deck_ship->setRotation(rotate_angle);
    one_deck_ship->setRotation(rotate_angle);
}

void LocationSelectionScene::drawShips()
{
/*
    one_ship->setTransformOriginPoint(one_ship->boundingRect().center());
    one_ship->setRotation(360);

    two_ship->setTransformOriginPoint(two_ship->boundingRect().center());
    two_ship->setRotation(360);


    three_ship->setTransformOriginPoint(three_ship->boundingRect().center());
    three_ship->setRotation(360);
*/
}

void LocationSelectionScene::createShipsIkons()
{
    QPixmap four_deck_ship_pixmap(":/resources/ships_images/old/four_battleship-removebg.png");
    four_deck_ship = new QGraphicsPixmapItem(
        four_deck_ship_pixmap.scaled(132, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    four_deck_ship->setTransformOriginPoint(four_deck_ship->boundingRect().center());
    four_deck_ship->setPos(363,33);
    addItem(four_deck_ship);

    QPixmap three_deck_ship_pixmap(":/resources/ships_images/old/three_battleship-removebg.png");
    three_deck_ship = new QGraphicsPixmapItem(
        three_deck_ship_pixmap.scaled(99, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    three_deck_ship->setPos(363, 165);
    three_deck_ship->setTransformOriginPoint(three_deck_ship->boundingRect().center());
    addItem(three_deck_ship);

    QPixmap two_deck_ship_pixmap(":/resources/ships_images/old/two_battleship-removebg.png");
    two_deck_ship = new QGraphicsPixmapItem(
        two_deck_ship_pixmap.scaled(66, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    two_deck_ship->setTransformOriginPoint(two_deck_ship->boundingRect().center());
    two_deck_ship->setPos(363, 264);
    addItem(two_deck_ship);

    QPixmap one_deck_ship_pixmap(":/resources/ships_images/old/one_battleship-removebg.png");
    one_deck_ship = new QGraphicsPixmapItem(
        one_deck_ship_pixmap.scaled(33, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    one_deck_ship->setTransformOriginPoint(one_deck_ship->boundingRect().center());
    one_deck_ship->setPos(363, 330);
    addItem(one_deck_ship);
}
