#include "gamelogemodel.h"

GameLogeModel::GameLogeModel (QTextEdit *label) :label(label) {}

void GameLogeModel::writeGameLog(CellType type, bool readFromEnemy, bool isMyTurn)
{
    switch (type) {
    case CellType::MISS:
        str = "MISS";
        miss = true;
        break;
    case CellType::DESTROYED:
        str = "DESTROYED";
        miss = false;
        break;
    case CellType::HURT:
        str = "HURT";
        miss = false;
        break;
    }
    previousLogs = label->toPlainText();

    QTimer::singleShot(300, [this, readFromEnemy, isMyTurn](){
        if(readFromEnemy){
            label->setPlainText("Enemy " + str + (!miss ? " your boat\n": "\n") + previousLogs);

        }else {
            label->setPlainText("You " + str + (!miss ? " enemy`s boat\n": "\n") + previousLogs);
        }

        QTimer::singleShot(400, [this, isMyTurn](){
            previousLogs = label->toPlainText();
            str = (isMyTurn ? "Now it`s your turn\n":"Enemy is taking their turn\n") + previousLogs;
            label->setPlainText(str);
        });

    });

}
