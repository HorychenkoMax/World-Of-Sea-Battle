#ifndef LINKMODEL_H
#define LINKMODEL_H
#include <QMap>
#include <QVector>

class LinkModel
{
private:
    static LinkModel *linkModel;
    LinkModel();

    QMap<QString, QString> exist_skins_for_boat{
                                                {"old", ":/resources/ships_images/old/four_battleship/left.png"}
    };
    QVector<QString> ship_direction_path {
        "/left.png",
        "/down.png",
        "/right.png",
        "/up.png"
    };
    QString start_of_path = ":/resources/ships_images/";
    QString selected_skin = "old";  //it`s hard code
    QVector<QString> ships_size_path{
        "/one_battleship",
        "/two_battleship",
        "/three_battleship",
        "/four_battleship"
    };
    QString cut = "/cut";
    QString destroyed = cut + "/destroyed";
    QVector<QString> ship_cut_number{
        "/1.png",
        "/2.png",
        "/3.png",
        "/4.png"
    };

public:
    static LinkModel* init();
    QMap<QString, QString> getSkinsMap();
    QVector<QVector<QString>> getListOfShipsIconsPath();
    QVector<QVector<QString>> getListOfShipPath();
    QVector<QVector<QString>> getListOfDestroyedShipPath();
    QVector<QString> getDistroyedPathBySize(qint32 size);

};

#endif // LINKMODEL_H
