#include "gamelogemodel.h"

void GameLogeModel::increaseNumberOfBoat(qint32 size)
{
    switch (size) {
    case 1:
        one_deck++;
        break;
    case 2:
        two_deck++;
        break;
    case 3:
        three_deck++;
        break;
    case 4:
        four_deck++;
        break;
    }
    allBoat++;
}

GameLogeModel::GameLogeModel (QTextEdit *logs, QTextEdit *information) :logs(logs), information(information) {}

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
    previousLogs = logs->toPlainText();

    QTimer::singleShot(300, [this, readFromEnemy, isMyTurn](){
        if(readFromEnemy){
            logs->setPlainText("Enemy " + str + (!miss ? " your boat\n": "\n") + previousLogs);

        }else {
            logs->setPlainText("You " + str + (!miss ? " enemy`s boat\n": "\n") + previousLogs);
        }

        QTimer::singleShot(400, [this, isMyTurn](){
            previousLogs = logs->toPlainText();
            str = (isMyTurn ? "Now it`s your turn\n":"Enemy is taking their turn\n") + previousLogs;
            logs->setPlainText(str);
        });

    });

}

void GameLogeModel::writeCounter(qint32 size)
{
    if(size != 0){
        increaseNumberOfBoat(size);
    }
    information->setPlainText("You destroyed:\nfour-deck: " + QString::number(four_deck) + "/1\nthree-deck: " + QString::number(three_deck) +
                              "/2\ntwo-deck: " + QString::number(two_deck) + "/3\nsingle-deck: " + QString::number(one_deck) + "/4");
}
