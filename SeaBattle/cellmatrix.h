#ifndef CELLMATRIX_H
#define CELLMATRIX_H

#include "celltype.h"
#include "qtypes.h"

class CellMatrix{
private:
    static const qint32 SIZE = 10;

    CellType cells[SIZE][SIZE];


public:
    CellType operator ()(qint32 index1, qint32 index2) const;
    CellType& operator () (qint32 index1, qint32 index2);

};

#endif // CELLMATRIX_H
