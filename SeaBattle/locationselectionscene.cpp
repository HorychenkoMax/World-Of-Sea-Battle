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

bool LocationSelectionScene::isCorrectPosition(qint32 boat_i, qint32 boat_j)
{
    if((current_ship.boat.getDirection() == Direction::LEFT || current_ship.boat.getDirection() == Direction::RIGHT)
        && current_ship.boat.getSize() > cells[boat_i].size() - boat_j) return false;
    if((current_ship.boat.getDirection() == Direction::DOWN || current_ship.boat.getDirection() == Direction::UP)
        && current_ship.boat.getSize() > cells.size() - boat_i) return false;


    qint32 size_i = current_ship.boat.getSize();
    qint32 size_j = current_ship.boat.getSize();

    switch (current_ship.boat.getDirection()) {
    case Direction::LEFT :
    case Direction::RIGHT:
        size_i = 1;
        break;
    default:
        size_j = 1;
    }

    for(qint32 i = qMax(boat_i - 1, 0); i < qMin(size_i + 1 + boat_i, 10); i++){
        for(qint32 j = qMax(boat_j - 1, 0); j < qMin(size_j + 1 + boat_j, 10); j++){
            if(cell_matrix(i,j) == CellType::BOAT) return false;
        }
    }

    return true;
}

void LocationSelectionScene::update()
{

    if(direction == Direction::LEFT){
        for(int i = 0; i < ship_icons_arr.size(); i++){
            qDebug() << ship_icons_arr[i].count;
            if(ship_icons_arr[i].count != 0) ship_icons_arr[i].image_left->setOpacity(1);
        }
    }else if(direction == Direction::DOWN){
        for(int i = 0; i < ship_icons_arr.size(); i++){
            if(ship_icons_arr[i].count != 0) ship_icons_arr[i].image_down->setOpacity(1);
        }
    } else if(direction == Direction::RIGHT){
        for(int i = 0; i < ship_icons_arr.size(); i++){
            if(ship_icons_arr[i].count != 0) ship_icons_arr[i].image_right->setOpacity(1);
        }
    } else if(direction == Direction::UP){
        for(int i = 0; i < ship_icons_arr.size(); i++){
            if(ship_icons_arr[i].count != 0) ship_icons_arr[i].image_up->setOpacity(1);
        }
    }
}


void LocationSelectionScene::fillBoatInMatrix(const Boat &boat, CellType type)
{
    //fillMatrix(boat, CellType::BOAT_BOARDER);
    qint32 i = boat.getHeadRow();
    qint32 j = boat.getHeadColumn();
    qint32 delta_i = 0;
    qint32 delta_j = 0;

    switch (boat.getDirection()) {
    case Direction::LEFT :
    case Direction::RIGHT:
        delta_j = 1;
        break;
    default:
        delta_i = 1;
    }

    for(qint32 x = 0; x < boat.getSize(); x++){
        cell_matrix(i + x*delta_i,j + x*delta_j) = type;
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
            //rect->setBrush(QColor("red"));
            rect->setOpacity(0);
            addItem(rect);


            QGraphicsPixmapItem *new_image = new QGraphicsPixmapItem(image->pixmap());
            new_image->setPos(image->pos());
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

    for(auto &ship:ship_board_arr){
        qDebug() << ship.item->contains(event->scenePos()) << ship.item->rect() << event->scenePos();
        if(ship.item->contains(event->scenePos())){
            qDebug() << "yes";
            current_ship.image = ship.image;
            current_ship.item = ship.item;
            current_ship.boat = ship.boat;
            fillBoatInMatrix(current_ship.boat, CellType::NONE);
            ship_board_arr.removeOne(ship);
            break;
        }
    }

}

void LocationSelectionScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!current_ship.image || !current_ship.item) return;
    current_ship.image->setPos(event->scenePos());
}

void LocationSelectionScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    if(!current_ship.image || !current_ship.item) return;

    for(int i = 0; i < cells.size(); i++){
        for(int j = 0; j < cells[i].size(); j++){

            if(cells[i][j].item->contains(event->scenePos())){

                if(isCorrectPosition(i,j)){
                current_ship.image->setPos(cells[i][j].item->rect().x(), cells[i][j].item->rect().y());
                current_ship.item->setRect(cells[i][j].item->rect().x(), cells[i][j].item->rect().y(), current_ship.item->rect().width(), current_ship.item->rect().height());
                current_ship.boat.setHeadRow(i);
                current_ship.boat.setHeadColumn(j);
                ship_board_arr.append(current_ship);
                fillBoatInMatrix(current_ship.boat);
                current_ship.item = nullptr;
                current_ship.image = nullptr;
                return;
                }
            }

        }
    }
    for(auto &ship:ship_icons_arr){
        if(ship.size == current_ship.boat.getSize()){
            ship.count++;
        }
    }
    update();
    delete current_ship.image;
    delete current_ship.item;
    current_ship.item = nullptr;
    current_ship.image = nullptr;


}






ShipIconItem::ShipIconItem(qint32 size, qint32 count): size(size), count(count)
{

}

bool BoatItem::operator ==(const BoatItem &boatItem) const
{
    return this == &boatItem;
}
