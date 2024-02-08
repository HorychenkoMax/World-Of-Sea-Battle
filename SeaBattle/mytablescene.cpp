#include "mytablescene.h"

MyTableScene::MyTableScene(QObject *parent)
    : BattlefieldScene{parent}
{
    createBattlefield();
}

