#ifndef LOCATIONSELECTIONSCENE_H
#define LOCATIONSELECTIONSCENE_H

#include "battlefieldscene.h"
#include "direction.h"
#include <QGraphicsSceneMouseEvent>
#include "boat.h"
#include "cellmatrix.h"

struct BoatItem : public Cell
{
    Boat boat;
    bool operator == (const BoatItem &boatItem) const;
};

struct ShipIconItem
{
    ShipIconItem(qint32 size, qint32 count);
    QGraphicsRectItem *item;
    QGraphicsPixmapItem *image_left;
    QGraphicsPixmapItem *image_right;
    QGraphicsPixmapItem *image_down;
    QGraphicsPixmapItem *image_up;
    qint32 size, count;
};


class LocationSelectionScene : public BattlefieldScene
{
public:
    explicit LocationSelectionScene(QObject *parent = nullptr);

    void rotate();

private:

    QVector<QVector<QString>> path {{":/resources/ships_images/old/one_battleship/one_battleship-left.png",":/resources/ships_images/old/one_battleship/one_battleship-down.png",
                                    ":/resources/ships_images/old/one_battleship/one_battleship-right.png",":/resources/ships_images/old/one_battleship/one_battleship-up.png"},
                                   {":/resources/ships_images/old/two_battleship/two_battleship-left.png",":/resources/ships_images/old/two_battleship/two_battleship-down.png",
                                    ":/resources/ships_images/old/two_battleship/two_battleship-right.png",":/resources/ships_images/old/two_battleship/two_battleship-up.png"},
                                   {":/resources/ships_images/old/three_battleship/three_battleship-left.png",":/resources/ships_images/old/three_battleship/three_battleship-down.png",
                                    ":/resources/ships_images/old/three_battleship/three_battleship-right.png",":/resources/ships_images/old/three_battleship/three_battleship-up.png"},
                                   {":/resources/ships_images/old/four_battleship/four_battleship-left.png",":/resources/ships_images/old/four_battleship/four_battleship-down.png",
                                    ":/resources/ships_images/old/four_battleship/four_battleship-right.png",":/resources/ships_images/old/four_battleship/four_battleship-up.png"}};
    QVector<qint32> delta {1,2,4,7};


    Direction direction = Direction::LEFT;
    QVector<ShipIconItem> ship_icons_arr;
    QVector<BoatItem> ship_board_arr;
    BoatItem current_ship;
    CellMatrix cell_matrix;
    qint32 x_pos = 366, y_pos = 33;
    qint32 w = 33, h = 33;
    qint32 max_count = 5;


    void drawShips();
    void createShipsIkons();
    bool isCorrectPosition(qint32 boat_i, qint32 boat_j);
    void update();
    void fillBoatInMatrix(const Boat &boat, CellType type = CellType::BOAT);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


};

#endif // LOCATIONSELECTIONSCENE_H
