#ifndef CONNECTIONPROPERTIES_H
#define CONNECTIONPROPERTIES_H

#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>

class ConnectionProperties
{
private:
    static ConnectionProperties* conectionProperties;

    const QString FILE_NAME = "connectionInformation.txt";

    QString my_host_id, other_host_id;
    qint32 my_port, other_port;

    ConnectionProperties();

public:
    static ConnectionProperties* init(); 

    void saveInformation();
    void downloadInformation();
    bool corectInformationForHosting();
    bool corectInformationForConnection();


    void setAllInformation(const QString &my_host_id = "", const QString &other_host_id = "", qint32 my_port = 0, qint32 other_port = 0);

    QString getMy_host_id() const;
    void setMy_host_id(const QString &newMy_host_id);

    QString getOther_host_id() const;
    void setOther_host_id(const QString &newOther_host_id);

    qint32 getMy_port() const;
    void setMy_port(qint32 newMy_port);

    qint32 getOther_port() const;
    void setOther_port(qint32 newOther_port);

};

#endif // CONNECTIONPROPERTIES_H
