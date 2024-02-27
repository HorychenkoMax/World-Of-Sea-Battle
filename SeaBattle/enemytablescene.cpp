#include "enemytablescene.h"

EnemyTableScene::EnemyTableScene(QObject *parent)
    : BattlefieldScene{parent}
{
    createBattlefield();
    drawFog();
    createPixmaps();
}

void EnemyTableScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    for(int i = 0; i < cells.size(); i++){
        for(int j = 0; j < cells[i].size(); j++){
            if(cells[i][j].item->contains(event->scenePos())){
                if(current_item_pos_i != -1 && current_item_pos_j != -1){
                     cells[current_item_pos_i][current_item_pos_j].image->setPixmap(fog);
                }
                current_item_pos_i = i;
                current_item_pos_j = j;
                qDebug() << i+1 <<(char)(j+'A');
                cells[i][j].image->setPixmap(sight);
            }
        }
    }
}

void EnemyTableScene::drawFog()
{
    for(int i = 0; i < cells.size(); i++){
        for(int j = 0; j < cells[i].size(); j++){

            QPixmap fog_pixmap(":/resources/game_window_images/fog.png");
            //QGraphicsPixmapItem* fog = new QGraphicsPixmapItem(fog_pixmap.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            //fog->setPos(delta_pos_x, delta_pos_y);
            //addItem(fog);
            //delta_pos_x += w_rect;
            cells[i][j].image->setPixmap(fog_pixmap.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        }
        delta_pos_x = 0;
        delta_pos_y += h_rect;
    }
}

qint32 EnemyTableScene::getCurrent_item_pos_i() const
{
    return current_item_pos_i;
}

qint32 EnemyTableScene::getCurrent_item_pos_j() const
{
    return current_item_pos_j;
}

void EnemyTableScene::createPixmaps()
{
    sight = QPixmap(":/resources/game_window_images/sight.png");
    sight = sight.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fog = QPixmap(":/resources/game_window_images/fog.png");
    fog = fog.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
