#ifndef GAMELOGEMODEL_H
#define GAMELOGEMODEL_H

#include <QString>
#include <QTextEdit>
#include <QTimer>
#include "models/celltype.h"

class GameLogeModel
{
private:
    QTextEdit *label;
    QString str;
    QString previousLogs;
    bool miss;
public:
    GameLogeModel(QTextEdit *label);

    void writeGameLog(CellType type, bool readFromEnemy, bool isMyTurn);
};

#endif // GAMELOGEMODEL_H
