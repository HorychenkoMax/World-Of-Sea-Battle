#include "boat.h"



qint32 Boat::getHeadRow() const
{
    return head_row;
}

void Boat::setHeadRow(qint32 newHead_row)
{
    head_row = newHead_row;
}

qint32 Boat::getHeadColumn() const
{
    return head_column;
}

void Boat::setHeadColumn(qint32 newHead_column)
{
    head_column = newHead_column;
}

Boat::Boat(qint32 head_row, qint32 head_column, qint32 size, Direction direction)
    : head_row{head_row}, head_column{head_column}, size{size}, direction{direction}
{

}

bool Boat::contains(qint32 given_row, qint32 given_column)
{
    switch (direction) {
    case Direction::LEFT:
        return head_row == given_row && (given_column <= head_column && given_column > head_column - size);
    case Direction::RIGHT:

        return head_row == given_row && (given_column >= head_column && given_column < head_column + size);
    case Direction::UP:

        return head_column == given_column && (given_row <= head_row && given_row > head_row - size);
    case Direction::DOWN:

        return head_column == given_column && (given_row >= head_row && given_row < head_row + size);
    }
}

void Boat::damage()
{
    damage_number_of_boat++;
}

bool Boat::isDestroyed()
{
    return damage_number_of_boat >= size;
}
