#include "models/connectionproperties.h"

ConnectionProperties* ConnectionProperties::conectionProperties = nullptr;

ConnectionProperties::ConnectionProperties() {}

ConnectionProperties *ConnectionProperties::init()
{
    if(conectionProperties==nullptr){
        conectionProperties = new ConnectionProperties();
        conectionProperties->downloadInformation();
    }

    return conectionProperties;
}


void ConnectionProperties::saveInformation()
{
    QFile file(FILE_NAME);

    if(!file.open(QFile::WriteOnly)){
        qDebug() << "cant open for write";
        return;
    }

    QTextStream stream(&file);

    stream << "my_host_id:" <<my_host_ip << "\n";
    stream << "my_port:" << my_port << "\n";
    stream << "other_host_id:" << other_host_ip << "\n";
    stream << "other_port:" << other_port << "\n";

    file.close();
}

void ConnectionProperties::downloadInformation()
{
    QFile file(FILE_NAME);

    if(!file.open(QFile::ReadOnly)){
        qDebug() << "cant open for read";
        return;
    }


    QTextStream stream(&file);
    QString line;

    while (!stream.atEnd()) {

        line = stream.readLine();
        my_host_ip = line.sliced(11);

        line = stream.readLine();
        my_port = line.sliced(8).toInt();

        line = stream.readLine();
        other_host_ip = line.sliced(14);

        line = stream.readLine();
        other_port = line.sliced(11).toInt();
    }

    file.close();
}

bool ConnectionProperties::corectInformationForHosting()
{
    QRegularExpressionMatch match = ipRegex.match(my_host_ip);
    return match.hasMatch() && my_port > 0;
}

bool ConnectionProperties::corectInformationForConnection()
{
    QRegularExpressionMatch match = ipRegex.match(other_host_ip);
    return match.hasMatch() && other_port > 0;
}

void ConnectionProperties::setAllInformation(const QString &my_host_id, const QString &other_host_id, qint32 my_port, qint32 other_port)
{
    this->my_host_ip = my_host_id;
    this->other_host_ip = other_host_id;
    this->my_port = my_port;
    this->other_port = other_port;
    saveInformation();
}

QString ConnectionProperties::getMy_host_id() const
{
    return my_host_ip;
}

void ConnectionProperties::setMy_host_id(const QString &newMy_host_id)
{
    my_host_ip = newMy_host_id;
}

QString ConnectionProperties::getOther_host_id() const
{
    return other_host_ip;
}

void ConnectionProperties::setOther_host_id(const QString &newOther_host_id)
{
    other_host_ip = newOther_host_id;
}

qint32 ConnectionProperties::getMy_port() const
{
    return my_port;
}

void ConnectionProperties::setMy_port(qint32 newMy_port)
{
    my_port = newMy_port;
}

qint32 ConnectionProperties::getOther_port() const
{
    return other_port;
}

void ConnectionProperties::setOther_port(qint32 newOther_port)
{
    other_port = newOther_port;
}



