#ifndef LOCATIONSELECTIONSCENE_H
#define LOCATIONSELECTIONSCENE_H

#include "scenes/battlefieldscene.h"
#include "models/direction.h"
#include <QGraphicsSceneMouseEvent>
#include "models/boat.h"
#include "models/cellmatrix.h"
#include "models/linkmodel.h"

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
    QVector<Boat> fromBooatItemToBoat();

    CellMatrix getCell_matrix() const;

    bool isAllShipsOnBoard();

private:
    QVector<qint32> delta {1,2,4,7};


    Direction direction = Direction::LEFT;
    QVector<ShipIconItem> ship_icons_arr;
    QVector<BoatItem> ship_board_arr;
    BoatItem current_ship;
    CellMatrix cell_matrix;
    qint32 x_pos = 366, y_pos = 33;
    qint32 w = 33, h = 33;
    qint32 max_count = 5;



    void createShipsIkons();
    bool isCorrectPosition(qint32 boat_i, qint32 boat_j);
    void update();
    void fillBoatInMatrix(const Boat &boat, CellType type = CellType::BOAT);



    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


};

#endif // LOCATIONSELECTIONSCENE_H
