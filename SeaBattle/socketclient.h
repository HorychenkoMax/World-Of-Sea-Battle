#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QObject>
#include <QTcpSocket>

class SocketClient : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;

    void connectAll();
public:
    explicit SocketClient();
    explicit SocketClient(QTcpSocket *socket);
    SocketClient(const SocketClient &client);
    void send(const QString &data);
    void run(const QString &host, qint32 port);

private slots:
    void connected();
    void disconnected();
    void readyRead();


signals:
};

#endif // SOCKETCLIENT_H
