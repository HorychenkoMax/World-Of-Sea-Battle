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
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
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
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            if(i == 0 || j == 0) {
                delta_pos_x += w_rect;
                continue;
            }
            QPixmap fog_pixmap(":/resources/game_window_images/fog.png");
            QGraphicsPixmapItem* fog = new QGraphicsPixmapItem(fog_pixmap.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            fog->setPos(delta_pos_x, delta_pos_y);
            addItem(fog);
            delta_pos_x += w_rect;
            cells[i-1][j-1].image = fog;
        }
        delta_pos_x = 0;
        delta_pos_y += h_rect;
    }
}

void EnemyTableScene::createPixmaps()
{
    sight = QPixmap(":/resources/game_window_images/sight.png");
    sight = sight.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    fog = QPixmap(":/resources/game_window_images/fog.png");
    fog = fog.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
