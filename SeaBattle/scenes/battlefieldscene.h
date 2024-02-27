#ifndef BATTLEFIELDSCENE_H
#define BATTLEFIELDSCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <QGraphicsTextItem>
#include <QVector>
#include <QGraphicsSceneMouseEvent>

struct Cell
{
    QGraphicsRectItem *item = nullptr;
    QGraphicsPixmapItem *image = nullptr;
};


class BattlefieldScene : public QGraphicsScene
{
public:
    explicit BattlefieldScene(QObject *parent = nullptr);

    explicit BattlefieldScene(qint32 w_background, qint32 h_background, QObject *parent = nullptr);

    void createBattlefield();
protected:
    qint32 w_background = 363, h_background = 363, w_rect = 33, h_rect = 33;
    qint32 delta_pos_x = 0, delta_pos_y = 0;
    QVector<QVector<Cell>> cells;


};

#endif // BATTLEFIELDSCENE_H
