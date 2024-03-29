#include "scenes/mytablescene.h"

MyTableScene::MyTableScene(MediaPlayer *player, QObject *parent)
    : BattlefieldScene{parent}
    , player(player)
{
    createBattlefield();
}

void MyTableScene::drawBoats(const QVector<Boat> boats)
{
    QVector<QVector<QString>> path = LinkModel::init()->getListOfShipPath();
    QVector<QVector<QString>> destroyedPath = LinkModel::init()->getListOfDestroyedShipPath();
    for(int i = 0; i < boats.size(); i++){
        qint32 current_boat_row = 0;
        qint32 current_boat_column = 0;
       // qint32 path_size = 0;
        switch (boats[i].getDirection()) {
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
        for(int j = 0; j < boats[i].getSize(); j++){

            if(rotation_angle == 270 || rotation_angle == 180){
                QPixmap destroyed_pixmap(destroyedPath[boats[i].getSize()-1][j]);
                QGraphicsPixmapItem *destroyed = cells[boats[i].getHeadRow() + current_boat_row * j][boats[i].getHeadColumn() + current_boat_column * j].destroyedImage;
                destroyed->setPixmap(destroyed_pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
                destroyed->setTransformOriginPoint(destroyed->boundingRect().center());
                destroyed->setRotation(rotation_angle);
                destroyed->hide();

                QPixmap ship_pixmap(path[boats[i].getSize()-1][j]);
                QGraphicsPixmapItem *ship =  cells[boats[i].getHeadRow() + current_boat_row * j][boats[i].getHeadColumn() + current_boat_column * j].image;
                ship->setPixmap(ship_pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
                ship->setTransformOriginPoint(ship->boundingRect().center());
                ship->setRotation(rotation_angle);
            }else {
                QPixmap destroyed_pixmap(destroyedPath[boats[i].getSize()-1][(boats[i].getSize()-1)-j]);
                QGraphicsPixmapItem *destroyed = cells[boats[i].getHeadRow() + current_boat_row * j][boats[i].getHeadColumn() + current_boat_column * j].destroyedImage;
                destroyed->setPixmap(destroyed_pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
                destroyed->setTransformOriginPoint(destroyed->boundingRect().center());
                destroyed->setRotation(rotation_angle);
                destroyed->hide();

                QPixmap ship_pixmap(path[boats[i].getSize()-1][(boats[i].getSize()-1)-j]);
                QGraphicsPixmapItem *ship =  cells[boats[i].getHeadRow() + current_boat_row * j][boats[i].getHeadColumn() + current_boat_column * j].image;
                ship->setPixmap(ship_pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
                ship->setTransformOriginPoint(ship->boundingRect().center());
                ship->setRotation(rotation_angle);
            }
        }
    }
}

void MyTableScene::drawEffect(qint32 i, qint32 j, CellType type)
{
    if(type == CellType::MISS){
        QPixmap splater(":/resources/effects/splater.png");
        cells[i][j].image->setPixmap(splater.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        player->paly(MusicType::MISS_MUSIC);
    }else if(type == CellType::HURT || type == CellType::DESTROYED){
        //QPixmap boom(":/resources/effects/boom.png");
        //cells[i][j].image->setPixmap(boom.scaled(w_rect, h_rect, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        cells[i][j].image->hide();
        cells[i][j].destroyedImage->show();
        player->paly(MusicType::BLAST_MUSIC);
    }
}


