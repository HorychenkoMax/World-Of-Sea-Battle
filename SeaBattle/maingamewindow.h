#ifndef MAINGAMEWINDOW_H
#define MAINGAMEWINDOW_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPixmap>
#include "mytablescene.h"
#include "enemytablescene.h"

namespace Ui {
class MainGameWindow;
}

class MainGameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainGameWindow(QWidget *parent = nullptr);
    ~MainGameWindow();

private:
    Ui::MainGameWindow *ui;
    MyTableScene *myTableScene;
    EnemyTableScene *enemyTableScene;

    void setBackground();


};

#endif // MAINGAMEWINDOW_H
