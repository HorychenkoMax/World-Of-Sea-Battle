#include "socket/socketclient.h"



bool SocketClient::getIsMyTurn() const
{
    return isMyTurn;
}

void SocketClient::disconnectFromHost()
{
    socket->close();
}

void SocketClient::connectAll()
{
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

SocketClient::SocketClient()
{
    socket = new QTcpSocket();
    connectAll();
}

SocketClient::SocketClient(QTcpSocket *socket, bool isMyTurn)
    : socket(socket)
    , isMyTurn(isMyTurn)
{
    connectAll();
}

SocketClient::SocketClient(const SocketClient &client)
{
    socket = client.socket;
    connectAll();
}

void SocketClient::send(const QString &data)
{
    socket->write(data.toStdString().c_str());
    if(!socket->waitForBytesWritten(3000)){
        qDebug() << socket->errorString();
    }
}

void SocketClient::run(const QString &host, qint32 port)
{
    socket->connectToHost(host,port);
}

void SocketClient::connected()
{
    qDebug() << "connected";
    emit(connectedToHost());
}

void SocketClient::disconnected()
{
    emit(oponentDisconnected());
}

void SocketClient::readyRead()
{
    QString string(socket->readAll());
    if(string.startsWith("isMyTurn=")){
        qint32 number = string.sliced(9).toInt();
        isMyTurn = number == 1;
    }else{
        emit(readFromOponent(string));
    }
}
