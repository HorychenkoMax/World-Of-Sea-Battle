#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPixmap>
#include "mytablescene.h"
#include "enemytablescene.h"
#include "battlemodel.h"

namespace Ui {
class MainGameWindow;
}

class MainGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGameWindow(BattleModel *battleModel ,QWidget *parent = nullptr);
    ~MainGameWindow();

private:
    Ui::MainGameWindow *ui;
    MyTableScene *myTableScene;
    EnemyTableScene *enemyTableScene;
    BattleModel *battleModel;

    QVector<Boat> boats;

    void setBackground();


};

#endif // MAINGAMEWINDOW_H
