#ifndef LOCATIONSELECTIONSCENE_H
#define LOCATIONSELECTIONSCENE_H

#include "battlefieldscene.h"
#include "direction.h"
#include <QGraphicsSceneMouseEvent>
#include "boat.h"

struct BoatItem : public Cell
{
    Boat boat;
};

struct SizeItem : public Cell
{
    SizeItem(qint32 size, qint32 count);
    qint32 size, count;
};

class LocationSelectionScene : public BattlefieldScene
{
public:
    explicit LocationSelectionScene(QObject *parent = nullptr);

    void rotate();

private:
    Direction direction = Direction::LEFT;
    qint32 rotate_angle = 0;
    QVector<SizeItem> ship_icons_arr;
    QVector<BoatItem> ship_board_arr;
    BoatItem current_ship;


    void drawShips();
    void createShipsIkons();

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


};

#endif // LOCATIONSELECTIONSCENE_H
