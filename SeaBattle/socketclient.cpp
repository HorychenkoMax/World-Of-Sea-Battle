#include "socketclient.h"



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

SocketClient::SocketClient(QTcpSocket *socket)
    : socket(socket)
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
}

void SocketClient::disconnected()
{
    qDebug() << "disconnected";
}

void SocketClient::readyRead()
{
    QString string(socket->readAll());
    qDebug() << string;
    if(string == "Hello from server"){

        qDebug() << "server say \"Hello from server \" ";
        send("Hi from client");
    }else if(string == "Hi from client"){
        qDebug() << "client say \" Hi from client \" ";
    }
}
