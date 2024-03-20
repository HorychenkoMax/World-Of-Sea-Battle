#include "scenes/enemytablescene.h"

EnemyTableScene::EnemyTableScene( MediaPlayer *player, QObject *parent)
    : BattlefieldScene{parent}
    , player(player)
{
    createBattlefield();
    createPixmaps();
    drawFog(); 
}

void EnemyTableScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    for(int i = 0; i < cells.size(); i++){
        for(int j = 0; j < cells[i].size(); j++){
            if(cells[i][j].item->contains(event->scenePos()) && !cells[i][j].isClicked){
                if(current_item_pos_i != -1 && current_item_pos_j != -1){
                    cells[current_item_pos_i][current_item_pos_j].image->setPixmap(fog);
                }
                current_item_pos_i = i;
                current_item_pos_j = j;
                //qDebug() << i+1 <<(char)(j+'A');
                cells[i][j].image->setPixmap(sight);
            }
        }
    }
}

void EnemyTableScene::drawFog()
{
    for(int i = 0; i < cells.size(); i++){
        for(int j = 0; j < cells[i].size(); j++){
            cells[i][j].image->setPixmap(fog);
        }
        delta_pos_x = 0;
        delta_pos_y += h_rect;
    }
}

void EnemyTableScene::drawEffect(qint32 i, qint32 j, CellType type)
{
    if(type == CellType::MISS){
        cells[i][j].image->setPixmap(splater);
        cells[i][j].isClicked = true;
        player->paly(MusicType::MISS_MUSIC);
    }else if(type == CellType::HURT){
        cells[i][j].image->setPixmap(boom);
        cells[i][j].isClicked = true;
        player->paly(MusicType::BLAST_MUSIC);
    }
}

void EnemyTableScene::setStartPosition()
{
    current_item_pos_i = -1;
    current_item_pos_j = -1;
}

void EnemyTableScene::drawDestroyed(qint32 headRow, qint32 headColumn, qint32 size, Direction direction)
{
    QVector<QString> path = LinkModel::init()->getDistroyedPathBySize(size);

    qint32 current_boat_row = 0;
    qint32 current_boat_column = 0;
    qint32 rotation_angle = 0;

    switch (direction) {
    case Direction::LEFT:
        rotation_angle = 0;
        current_boat_column = 1;
        break;
    case Direction::RIGHT:
        rotation_angle = 180;
        current_boat_column = 1;
        break;
    case Direction::DOWN:
        rotation_angle = 90;
        current_boat_row = 1;
        break;
    case Direction::UP:
        rotation_angle = 270;
        current_boat_row = 1;
        break;
    }

    for(int j = 0; j < size; j++){

        cells[headRow + (current_boat_row * j)][headColumn + (current_boat_column * j)].image->hide();
        QGraphicsPixmapItem *destroyed = cells[headRow + (current_boat_row * j)][headColumn + (current_boat_column * j)].destroyedImage;

        if(rotation_angle == 270 || rotation_angle == 180){
            QPixmap destroyed_pixmap(path[j]);
            destroyed->setPixmap(destroyed_pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        }else {
            QPixmap destroyed_pixmap(path[(size-1) - j]);
            destroyed->setPixmap(destroyed_pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        }

        destroyed->setTransformOriginPoint(destroyed->boundingRect().center());
        destroyed->setRotation(rotation_angle);
    }
    player->paly(MusicType::BLAST_MUSIC);
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
    splater = QPixmap(":/resources/effects/splater.png");
    splater = splater.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    boom = QPixmap(":/resources/effects/boom.png");
    boom = boom.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
}
