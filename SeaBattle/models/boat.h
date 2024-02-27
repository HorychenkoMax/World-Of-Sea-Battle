#ifndef BOAT_H
#define BOAT_H

#include <QString>
#include "models/direction.h"

class Boat
{

private:
    qint32 head_row, head_column, size, damage_number_of_boat;
    Direction direction;
public:
    Boat() = default;
    Boat(qint32 head_row, qint32 head_column, qint32 size, Direction direction);

    bool contains(qint32 given_row, qint32 given_column);
    void damage();
    bool isDestroyed();



    qint32 getHeadRow() const;
    void setHeadRow(qint32 newHead_row);
    qint32 getHeadColumn() const;
    void setHeadColumn(qint32 newHead_column);

    Direction getDirection() const;
    qint32 getSize() const;
};

#endif // BOAT_H
