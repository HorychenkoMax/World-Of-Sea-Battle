#include "models/battlemodel.h"


QVector<Boat> BattleModel::getBoats() const
{
    return boats;
}

Boat* BattleModel::getBoatByHisDeck(qint32 index1, qint32 index2)
{
    for(int i = 0; i < boats.size(); i++){
        if(boats[i].contains(index1, index2)) return &boats[i];
    }
    return nullptr;
}

void BattleModel::setCellsAsDestryed(const Boat &boat)
{
    qint32 delta_row = 0;
    qint32 delta_column = 0;
    if(boat.getDirection() == Direction::DOWN || boat.getDirection() == Direction::UP){
        delta_row = 1;
    }else {
        delta_column = 1;
    }

    for(int i = 0; i < boat.getSize(); i++){
        cells(boat.getHeadRow() + (i * delta_row), boat.getHeadColumn() + (i * delta_column)) = CellType::DESTROYED;
    }
}

BattleModel::BattleModel(const QVector<Boat> &boats, const CellMatrix &cells) : boats(boats), cells(cells)
{

}
CellType BattleModel::attack(qint32 index1, qint32 index2)
{
    CellType type = cells(index1, index2);
    if(type == CellType::HURT || type == CellType::DESTROYED || type == CellType::MISS) return CellType::ERROR;
    if(type == CellType::BOAT){
        Boat *boat = getBoatByHisDeck(index1, index2);
        if(boat == nullptr) return CellType::ERROR;
        boat->damage();
        if(boat->isDestroyed()){
            setCellsAsDestryed(*boat);
        }else {
            cells(index1, index2) = CellType::HURT;
        }
    }else if (type == CellType::NONE) {
        cells(index1, index2) = CellType::MISS;
    }
    return cells(index1, index2);
}
