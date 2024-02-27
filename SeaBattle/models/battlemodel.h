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
public:
    BattleModel(const QVector<Boat> &boats, const CellMatrix &cells);

    CellType attack(qint32 index1, qint32 index2);
    QVector<Boat> getBoats() const;
};

#endif // BATTLEMODEL_H
