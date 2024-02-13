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
    Direction direction = Direction::LEFT;
    qint32 rotate_angle = 0;
    QVector<Cell> ship_icons_arr;


    void drawShips();
    void createShipsIkons();


};

#endif // LOCATIONSELECTIONSCENE_H
