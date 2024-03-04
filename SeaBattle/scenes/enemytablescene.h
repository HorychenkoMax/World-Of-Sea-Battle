#ifndef ENEMYTABLESCENE_H
#define ENEMYTABLESCENE_H

#include "models/celltype.h"
#include "scenes/battlefieldscene.h"
#include "models/direction.h"
#include "models/linkmodel.h"

class EnemyTableScene : public BattlefieldScene
{
public:
    explicit EnemyTableScene(QObject *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void drawFog();
    void drawEffect(qint32 i, qint32 j, CellType type);
    void setStartPosition();
    void drawDestroyed(qint32 headRow, qint32 headColumn, qint32 size, Direction direction);

    qint32 getCurrent_item_pos_i() const;
    qint32 getCurrent_item_pos_j() const;

private:
    qint32 current_item_pos_i = -1, current_item_pos_j = -1;
    QPixmap fog, sight, splater, boom;
    qint32 w = 33, h = 33;

    void createPixmaps();
};

#endif // ENEMYTABLESCENE_H
