#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPixmap>
#include "mytablescene.h"
#include "enemytablescene.h"
#include "battlemodel.h"
#include "socketclient.h"

namespace Ui {
class MainGameWindow;
}

class MainGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGameWindow(SocketClient *client, BattleModel *battleModel ,QWidget *parent = nullptr);
    ~MainGameWindow();

private:
    Ui::MainGameWindow *ui;
    MyTableScene *myTableScene;
    EnemyTableScene *enemyTableScene;
    BattleModel *battleModel;
    SocketClient *client;
    bool isMyTurn;

    QVector<Boat> boats;

    void setBackground();

private slots:
    void readFromOponent(const QString &string);
    void on_attack_clicked();
};

#endif // MAINGAMEWINDOW_H
