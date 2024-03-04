#include "linkmodel.h"

LinkModel* LinkModel::linkModel = nullptr;

LinkModel::LinkModel() {}

LinkModel *LinkModel::init()
{
    if(linkModel == nullptr){
        linkModel = new LinkModel();
    }
    return linkModel;
}

QMap<QString, QString> LinkModel::getSkinsMap()
{
    return exist_skins_for_boat;
}

QVector<QVector<QString> > LinkModel::getListOfShipsIconsPath()
{
    QVector<QVector<QString>> path;
    for(int i = 0; i < 4; i++){
        QVector<QString> ship;
        for(int j = 0; j < 4; j++){
            QString str = start_of_path;
            str += selected_skin + ships_size_path[i] + ship_direction_path[j];
            ship.append(str);
        }
        path.append(ship);
    }
    return path;
}

QVector<QVector<QString> > LinkModel::getListOfShipPath()
{
    QVector<QVector<QString>> path;
    for(int i = 0; i < ships_size_path.size(); i++){
        QVector<QString> ship;
        QString str = "";
        if(i == 0){
            str += start_of_path + selected_skin + ships_size_path[i] + ship_direction_path[i];
            ship.append(str);
            path.append(ship);
            continue;
        }
        for(int j = 0; j < i+1; j++){
            str = "";
            str += start_of_path + selected_skin + ships_size_path[i] + cut + ship_cut_number[j];
            ship.append(str);
        }
        path.append(ship);
    }
    return path;
}

QVector<QVector<QString> > LinkModel::getListOfDestroyedShipPath()
{
    QVector<QVector<QString>> path;
    for(int i = 0; i < ships_size_path.size(); i++){
        QVector<QString> ship;
        QString str = "";
        if(i == 0){
            str += start_of_path + selected_skin + ships_size_path[i] + "/destroyed.png";
            ship.append(str);
            path.append(ship);
            continue;
        }
        for(int j = 0; j < i+1; j++){
            str = "";
            str += start_of_path + selected_skin + ships_size_path[i] + destroyed + ship_cut_number[j];
            ship.append(str);
        }
        path.append(ship);
    }
    return path;
}

QVector<QString> LinkModel::getDistroyedPathBySize(qint32 size)
{
    QVector<QString> path;
    QString str = "";
    if(size == 1){
        str += start_of_path + selected_skin + ships_size_path[size - 1] + "/destroyed.png";
        path.append(str);
        return path;
    }

    for(int i = 0; i < size; i++){
        str += start_of_path + selected_skin + ships_size_path[size - 1] + destroyed + ship_cut_number[i];
        path.append(str);
        str = "";
    }

    return path;
}


