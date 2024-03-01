#ifndef BATTLEMODEL_H
#define BATTLEMODEL_H

#include <QVector>
#include "models/boat.h"
#include "models/cellmatrix.h"

class BattleModel
{
private:
    QVector<Boat> boats;
    CellMatrix cells;

    void setCellsAsDestryed(const Boat &boat);
public:
    BattleModel(const QVector<Boat> &boats, const CellMatrix &cells);

    CellType attack(qint32 index1, qint32 index2);
    QVector<Boat> getBoats() const;
    Boat* getBoatByHisDeck(qint32 index1, qint32 index2);
};

#endif // BATTLEMODEL_H
