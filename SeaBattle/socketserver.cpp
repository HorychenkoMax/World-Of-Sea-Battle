#include "socketserver.h"

SocketServer::SocketServer()
{
    server = new QTcpServer();

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
    SocketClient client(socket);
    client.send("Hello from server");
    emit newClient(client);
}
