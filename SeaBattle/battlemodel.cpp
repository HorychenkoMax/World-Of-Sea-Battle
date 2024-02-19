#include "battlemodel.h"


QVector<Boat> BattleModel::getBoats() const
{
    return boats;
}

BattleModel::BattleModel(const QVector<Boat> &boats, const CellMatrix &cells) : boats(boats), cells(cells)
{

}
