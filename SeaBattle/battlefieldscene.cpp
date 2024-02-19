#include "battlefieldscene.h"

BattlefieldScene::BattlefieldScene(QObject *parent)
    : QGraphicsScene{parent}
{

    setBackgroundBrush(QColor(255, 255, 255));

}

BattlefieldScene::BattlefieldScene(qint32 w_background, qint32 h_background, QObject *parent) : w_background(w_background), h_background(h_background)
{
    setBackgroundBrush(QColor(255, 255, 255));

}

void BattlefieldScene::createBattlefield()
{
    setSceneRect(0, 0, w_background, h_background);

    QPixmap pixmap_background(":/resources/game_window_images/battlefildImage2.jpg");

    QGraphicsPixmapItem* background = new QGraphicsPixmapItem(
        pixmap_background.scaled(w_background, h_background, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    background->setPos(0, 0);
    addItem(background);


    QFont font;                         // font for numbers and letetrs on battlefield background
    font.setPixelSize(14);              //
    font.setBold(true);                 //

    for(int j = 0; j < 11; j++){

        QVector<Cell> cell_array;

        for(int i = 0; i < 11; i++){

            if(i == 0){
                QGraphicsRectItem *item = new QGraphicsRectItem();
                item->setRect(delta_pos_x, delta_pos_y, w_rect, h_rect);
                addItem(item);
                if(j != 0){
                    QGraphicsTextItem *text = new QGraphicsTextItem();
                    text->setPlainText(QString::number(j));
                    text->setPos(delta_pos_x, delta_pos_y);
                    text->setFont(font);
                    addItem(text);
                }
                delta_pos_x += w_rect;
                continue;
            }

            if(j == 0){
                QGraphicsRectItem *item = new QGraphicsRectItem();
                item->setRect(delta_pos_x, delta_pos_y, w_rect, h_rect);
                addItem(item);

                QGraphicsTextItem *text = new QGraphicsTextItem();
                QString leter;
                leter += (char)(i+'A' - 1);
                text->setPlainText(leter);
                text->setPos(delta_pos_x, delta_pos_y);
                text->setFont(font);
                addItem(text);

                delta_pos_x += w_rect;
                continue;
            }

            QGraphicsRectItem *rect = new QGraphicsRectItem();
            rect->setRect(delta_pos_x, delta_pos_y, w_rect, h_rect);
            addItem(rect);

            Cell cell;
            cell.item = rect;

            QGraphicsPixmapItem* image = new QGraphicsPixmapItem();
            image->setPos(delta_pos_x, delta_pos_y);
            addItem(image);

            delta_pos_x = delta_pos_x + w_rect;
            cell.image = image;
            cell_array.append(cell);

        }

        delta_pos_x = 0;
        delta_pos_y = delta_pos_y + h_rect;
        if(cell_array.size() > 0){
            cells.append(cell_array);
        }
    }
    delta_pos_x = 0;
    delta_pos_y = 0;
}
