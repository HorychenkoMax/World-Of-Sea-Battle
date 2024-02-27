#ifndef ENEMYTABLESCENE_H
#define ENEMYTABLESCENE_H

#include "battlefieldscene.h"

class EnemyTableScene : public BattlefieldScene
{
public:
    explicit EnemyTableScene(QObject *parent = nullptr);

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void drawFog();

    qint32 getCurrent_item_pos_i() const;
    qint32 getCurrent_item_pos_j() const;

private:
    qint32 current_item_pos_i = -1, current_item_pos_j = -1;
    QPixmap fog, sight;

    void createPixmaps();
};

#endif // ENEMYTABLESCENE_H
