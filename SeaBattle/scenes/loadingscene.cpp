#include "loadingscene.h"

LoadingScene::LoadingScene(QObject *parent)
    : QGraphicsScene{parent}
{
    setBackgroundBrush(QColor::fromRgb(0,0,0,0));
}
