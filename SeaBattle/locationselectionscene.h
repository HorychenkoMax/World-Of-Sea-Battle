#ifndef LOCATIONSELECTIONSCENE_H
#define LOCATIONSELECTIONSCENE_H

#include "battlefieldscene.h"
#include "direction.h"

class LocationSelectionScene : public BattlefieldScene
{
public:
    explicit LocationSelectionScene(QObject *parent = nullptr);

    void rotate();

private:
    QGraphicsPixmapItem *four_deck_ship;
    QGraphicsPixmapItem *three_deck_ship;
    QGraphicsPixmapItem *two_deck_ship;
    QGraphicsPixmapItem *one_deck_ship;
    Direction direction = Direction::LEFT;
    qint32 rotate_angle = 0;


    void drawShips();
    void createShipsIkons();


};

#endif // LOCATIONSELECTIONSCENE_H
