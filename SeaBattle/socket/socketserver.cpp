#include "socket/socketserver.h"

SocketServer::SocketServer()
{
    server = new QTcpServer();
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void SocketServer::run(const QString &host, qint32 port)
{
    if(server->listen(QHostAddress(host), port)){
        qDebug() << "vishlo";
    }else {
        qDebug() << "shos ne duze vishlo";
    }

}

void SocketServer::newConnection()
{
    QTcpSocket *socket = server->nextPendingConnection();
    qint32 number = QRandomGenerator::global()->bounded(0,1);
    SocketClient *client = new SocketClient(socket, number == 1);

    client->send("isMyTurn=" + QString::number(1 - number));
    emit newClient(client);
}
