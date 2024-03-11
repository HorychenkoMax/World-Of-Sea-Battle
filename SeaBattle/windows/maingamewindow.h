#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QMessageBox>
#include <QTimer>
#include "scenes/mytablescene.h"
#include "scenes/enemytablescene.h"
#include "models/battlemodel.h"
#include "socket/socketclient.h"
#include "models/gamelogemodel.h"

namespace Ui {
class MainGameWindow;
}

class MainGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGameWindow(SocketClient *client, BattleModel *battleModel ,QWidget *parent);
    ~MainGameWindow();


private:
    Ui::MainGameWindow *ui;
    QWidget *parent;
    MyTableScene *myTableScene;
    EnemyTableScene *enemyTableScene;
    BattleModel *battleModel;
    SocketClient *client;
    GameLogeModel *logModel;
    bool isMyTurn;
    qint32 current_i, current_j;
    qint32 numberOfDestroyedBoat = 0;

    QVector<Boat> boats;

    void setBackground();
    void writeGameLog(CellType type, bool readFromEnemy);
    bool isWin();

private slots:
    void readFromOponent(const QString &string);
    void on_attack_clicked();
    void oponentDisconnected();
};

#endif // MAINGAMEWINDOW_H
