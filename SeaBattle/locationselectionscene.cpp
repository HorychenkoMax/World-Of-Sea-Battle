#include "locationselectionscene.h"

LocationSelectionScene::LocationSelectionScene(QObject *parent)
    : BattlefieldScene{498, 365, parent}
{
    createBattlefield();
    createShipsIkons();
    //drawShips();
}

void LocationSelectionScene::rotate()
{
    if(direction == Direction::LEFT){
        direction = Direction::DOWN;
        for(int i = 0; i < ship_icons_arr.size(); i++){
            ship_icons_arr[i].image_left->hide();
            if(ship_icons_arr[i].count != 0) ship_icons_arr[i].image_down->show();
        }
    }else if(direction == Direction::DOWN){
        direction = Direction::RIGHT;
        for(int i = 0; i < ship_icons_arr.size(); i++){
            ship_icons_arr[i].image_down->hide();
            if(ship_icons_arr[i].count != 0) ship_icons_arr[i].image_right->show();
        }
    } else if(direction == Direction::RIGHT){
        direction = Direction::UP;
        for(int i = 0; i < ship_icons_arr.size(); i++){
            ship_icons_arr[i].image_right->hide();
            if(ship_icons_arr[i].count != 0) ship_icons_arr[i].image_up->show();
        }
    } else if(direction == Direction::UP){
        direction = Direction::LEFT;
        for(int i = 0; i < ship_icons_arr.size(); i++){
            ship_icons_arr[i].image_up->hide();
            if(ship_icons_arr[i].count != 0) ship_icons_arr[i].image_left->show();
        }
    }
}

void LocationSelectionScene::drawShips()
{

}

void LocationSelectionScene::createShipsIkons()
{
    for(int i = 1; i < path.size() + 1; i++){
        ShipIconItem icon(i, max_count -i);

        QGraphicsRectItem *rect = new QGraphicsRectItem();
        rect->setRect(x_pos, y_pos*delta[i-1], w*i, h*i);  //x - coordinate, y - coordinate, w - weight of rect, h - hight of rect
        rect->setOpacity(0);
        addItem(rect);
        icon.item = rect;


        for(int j = 0; j < 4; j++){
            QPixmap ship_pixmap(path[i-1][j]);
            QGraphicsPixmapItem *ship = new QGraphicsPixmapItem;
            if(j%2==0){
                ship->setPixmap(ship_pixmap.scaled(w*i, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            }else {
                ship->setPixmap(ship_pixmap.scaled(w, h*i, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
            }
            ship->setPos(x_pos,y_pos*delta[i-1]);
            addItem(ship);
            if(j == 0){
                icon.image_left = ship;

            } else if(j == 1){
                icon.image_down = ship;
                icon.image_down->hide();
            } else if(j == 2){
                icon.image_right = ship;
                icon.image_right->hide();
            }else if(j == 3){
                icon.image_up = ship;
                icon.image_up->hide();
            }

        }
        ship_icons_arr.append(icon);
    }
}

void LocationSelectionScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(current_ship.item) return;

    QGraphicsPixmapItem *image;

    for(auto &ship:ship_icons_arr){

        if(ship.item->contains(event->scenePos()) && ship.count > 0){

            switch (direction) {
            case Direction::LEFT:
                image = ship.image_left;
                break;
            case Direction::DOWN:
                image = ship.image_down;
                break;
            case Direction::RIGHT:
                image = ship.image_right;
                break;
            case Direction::UP:
                image = ship.image_up;
                break;

            }



            QGraphicsRectItem *rect = new QGraphicsRectItem();
            rect->setRect(image->boundingRect());
            rect->setPos(image->pos());
            rect->setBrush(QColor("red"));
            rect->setOpacity(1);
            addItem(rect);


            QGraphicsPixmapItem *new_image = new QGraphicsPixmapItem(image->pixmap());
            new_image->setTransformOriginPoint(image->boundingRect().center());
            new_image->setPos(image->pos());
            new_image->setRotation(image->rotation());
            addItem(new_image);


            current_ship.image = new_image;
            current_ship.item = rect;
            current_ship.boat = Boat(-1, -1, ship.size, direction);
            ship.count--;
            if(ship.count <= 0){
                image->setOpacity(0);

            }
        }
    }

}

void LocationSelectionScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!current_ship.image || !current_ship.item) return;
    current_ship.image->setPos(event->scenePos());
    current_ship.item->setPos(event->scenePos());
}

void LocationSelectionScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    if(!current_ship.image || !current_ship.item) return;
    for(int i = 0; i < cells.size(); i++){
        for(int j = 0; j < cells[i].size(); j++){

            if(cells[i][j].item->contains(event->scenePos())){

                current_ship.image->setPos(cells[i][j].item->rect().x(), cells[i][j].item->rect().y());
                current_ship.item->setPos(cells[i][j].item->rect().x(), cells[i][j].item->rect().y());
                current_ship.boat.setHeadRow(i);
                current_ship.boat.setHeadColumn(j);
                ship_board_arr.append(current_ship);
                current_ship.item = nullptr;
                current_ship.image = nullptr;

            }
        }
    }


}






ShipIconItem::ShipIconItem(qint32 size, qint32 count): size(size), count(count)
{

}
