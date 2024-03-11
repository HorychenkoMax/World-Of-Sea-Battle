#ifndef GAMELOGEMODEL_H
#define GAMELOGEMODEL_H

#include <QString>
#include <QTextEdit>
#include <QTimer>
#include "models/celltype.h"

class GameLogeModel
{
private:
    QTextEdit *logs;
    QTextEdit *information;
    QString str;
    QString previousLogs;
    bool miss;
    qint32 one_deck = 0;
    qint32 two_deck = 0;
    qint32 three_deck = 0;
    qint32 four_deck = 0;
    qint32 allBoat = 0;

    void increaseNumberOfBoat(qint32 size);
public:
    GameLogeModel(QTextEdit *logs, QTextEdit *information);

    void writeGameLog(CellType type, bool readFromEnemy, bool isMyTurn);
    void writeCounter(qint32 size);


};

#endif // GAMELOGEMODEL_H
