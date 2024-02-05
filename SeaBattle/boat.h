#ifndef BOAT_H
#define BOAT_H

#include <QString>
#include "direction.h"

class Boat
{

private:
    qint32 head_row, head_column, size, damage_number_of_boat;
    Direction direction;
public:
    Boat(qint32 head_row, qint32 head_column, qint32 size, Direction direction);
    bool contains(qint32 given_row, qint32 given_column);
    void damage();
    bool isDestroyed();

};

#endif // BOAT_H
