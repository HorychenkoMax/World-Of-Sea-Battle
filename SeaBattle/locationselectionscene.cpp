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
    for(int i = 0; i < 4; i++){
        ship_icons_arr[i].image->setRotation(rotate_angle);
        ship_icons_arr[i].item->setRotation(rotate_angle);
    }
}

void LocationSelectionScene::drawShips()
{

}

void LocationSelectionScene::createShipsIkons()
{

    QGraphicsRectItem *four_rect = new QGraphicsRectItem();
    four_rect->setRect(363, 33, 132, 33);
    four_rect->setTransformOriginPoint(four_rect->boundingRect().center());
    addItem(four_rect);

    QPixmap four_deck_ship_pixmap(":/resources/ships_images/old/four_battleship-removebg.png");
    QGraphicsPixmapItem *four_deck_ship = new QGraphicsPixmapItem(
        four_deck_ship_pixmap.scaled(132, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    four_deck_ship->setTransformOriginPoint(four_deck_ship->boundingRect().center());
    four_deck_ship->setPos(363,33);
    addItem(four_deck_ship);

    Cell four_cell;
    four_cell.image = four_deck_ship;
    four_cell.item = four_rect;
    ship_icons_arr.append(four_cell);

    QGraphicsRectItem *three_rect = new QGraphicsRectItem();
    three_rect->setRect(363, 165, 99, 33);
    three_rect->setTransformOriginPoint(three_rect->boundingRect().center());
    addItem(three_rect);

    QPixmap three_deck_ship_pixmap(":/resources/ships_images/old/three_battleship-removebg.png");
    QGraphicsPixmapItem *three_deck_ship = new QGraphicsPixmapItem(
        three_deck_ship_pixmap.scaled(99, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    three_deck_ship->setPos(363, 165);
    three_deck_ship->setTransformOriginPoint(three_deck_ship->boundingRect().center());
    addItem(three_deck_ship);

    Cell three_cell;
    three_cell.image = three_deck_ship;
    three_cell.item = three_rect;
    ship_icons_arr.append(three_cell);

    QGraphicsRectItem *two_rect = new QGraphicsRectItem();
    two_rect->setRect(363, 264, 66, 33);
    two_rect->setTransformOriginPoint(two_rect->boundingRect().center());
    addItem(two_rect);

    QPixmap two_deck_ship_pixmap(":/resources/ships_images/old/two_battleship-removebg.png");
    QGraphicsPixmapItem *two_deck_ship = new QGraphicsPixmapItem(
        two_deck_ship_pixmap.scaled(66, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    two_deck_ship->setTransformOriginPoint(two_deck_ship->boundingRect().center());
    two_deck_ship->setPos(363, 264);
    addItem(two_deck_ship);

    Cell two_cell;
    two_cell.image = two_deck_ship;
    two_cell.item = two_rect;
    ship_icons_arr.append(two_cell);

    QGraphicsRectItem *one_rect = new QGraphicsRectItem();
    one_rect->setRect(363, 330, 33, 33);
    one_rect->setTransformOriginPoint(one_rect->boundingRect().center());
    addItem(one_rect);

    QPixmap one_deck_ship_pixmap(":/resources/ships_images/old/one_battleship-removebg.png");
    QGraphicsPixmapItem *one_deck_ship = new QGraphicsPixmapItem(
        one_deck_ship_pixmap.scaled(33, 33, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    one_deck_ship->setTransformOriginPoint(one_deck_ship->boundingRect().center());
    one_deck_ship->setPos(363, 330);
    addItem(one_deck_ship);

    Cell one_cell;
    one_cell.image = one_deck_ship;
    one_cell.item = one_rect;
    ship_icons_arr.append(one_cell);
}
