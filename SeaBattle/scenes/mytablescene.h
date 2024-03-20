#ifndef MYTABLESCENE_H
#define MYTABLESCENE_H

#include <QGraphicsScene>
#include "scenes/battlefieldscene.h"
#include "models/boat.h"
#include "models/celltype.h"
#include "models/linkmodel.h"
#include "models/mediaplayer.h""

class MyTableScene : public BattlefieldScene
{
public:
    explicit MyTableScene(MediaPlayer *player, QObject *parent = nullptr);

    void drawBoats(const QVector<Boat> boats);
    void drawEffect(qint32 i, qint32 j, CellType type);

private:
    QVector<QVector<QGraphicsRectItem>> boats_matrix;
    qint32 rotation_angle = 0;
    qint32 w = 33, h = 33;
    MediaPlayer *player;
};

#endif // MYTABLESCENE_H
