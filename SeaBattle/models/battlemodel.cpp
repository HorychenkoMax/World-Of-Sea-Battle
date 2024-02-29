#include "models/battlemodel.h"


QVector<Boat> BattleModel::getBoats() const
{
    return boats;
}

BattleModel::BattleModel(const QVector<Boat> &boats, const CellMatrix &cells) : boats(boats), cells(cells)
{

}
// треба додати перевірки ну те чи знищений корабель
CellType BattleModel::attack(qint32 index1, qint32 index2)
{
    CellType type = cells(index1, index2);
    if(type == CellType::HURT || type == CellType::DESTROYED || type == CellType::MISS) return CellType::ERROR;
    if(type == CellType::BOAT){
        cells(index1, index2) = CellType::HURT;
    }else if (type == CellType::NONE) {
        cells(index1, index2) = CellType::MISS;
    }
    return cells(index1, index2);
}
