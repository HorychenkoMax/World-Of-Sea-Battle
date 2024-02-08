#ifndef MYTABLESCENE_H
#define MYTABLESCENE_H

#include <QGraphicsScene>
#include "battlefieldscene.h"

class MyTableScene : public BattlefieldScene
{
public:
    explicit MyTableScene(QObject *parent = nullptr);

};

#endif // MYTABLESCENE_H
