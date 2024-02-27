#ifndef MYTABLESCENE_H
#define MYTABLESCENE_H

#include <QGraphicsScene>
#include "scenes/battlefieldscene.h"
#include "models/boat.h"

class MyTableScene : public BattlefieldScene
{
public:
    explicit MyTableScene(QObject *parent = nullptr);

    void drawBoats(const QVector<Boat> boats);

private:
    QVector<QVector<QGraphicsRectItem>> boats_matrix;

    QVector<QVector<QString>> path {{":/resources/ships_images/old/one_battleship/one_battleship-left.png"},
                                   {":/resources/ships_images/old/two_battleship/two_battleship_cut/two_battleship-removebg_2.png",
                                    ":/resources/ships_images/old/two_battleship/two_battleship_cut/two_battleship-removebg_1.png"},
                                   {":/resources/ships_images/old/three_battleship/three_battleship_cut/three_battleship-removebg_3.png",
                                    ":/resources/ships_images/old/three_battleship/three_battleship_cut/three_battleship-removebg_2.png",
                                    ":/resources/ships_images/old/three_battleship/three_battleship_cut/three_battleship-removebg_1.png"},
                                   {":/resources/ships_images/old/four_battleship/four_battleship_cut/four_battleship-removebg_4.png",
                                    ":/resources/ships_images/old/four_battleship/four_battleship_cut/four_battleship-removebg_3.png",
                                    ":/resources/ships_images/old/four_battleship/four_battleship_cut/four_battleship-removebg_2.png",
                                    ":/resources/ships_images/old/four_battleship/four_battleship_cut/four_battleship-removebg_1.png"}};

    qint32 rotation_angle = 0;
    qint32 w = 33, h = 33;
};

#endif // MYTABLESCENE_H
