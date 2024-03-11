#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <QObject>
#include <QTcpServer>
#include "socket/socketclient.h"
#include <QRandomGenerator>


class SocketServer : public QObject
{
    Q_OBJECT
private:
    QTcpServer *server;
public:
    explicit SocketServer();
    ~SocketServer();
    bool run(const QString &host, qint32 port);
    void close();

signals:
    void newClient(SocketClient *client);

private slots:
    void newConnection();

};

#endif // SOCKETSERVER_H
