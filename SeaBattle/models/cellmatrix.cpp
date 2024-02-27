#include "models/cellmatrix.h"
//const qint32 CellMatrix::SIZE = 10;
CellType CellMatrix::operator ()(qint32 index1, qint32 index2) const{
    return cells[index1][index2];
}

CellType& CellMatrix::operator () (qint32 index1, qint32 index2){
    return cells[index1][index2];
}
