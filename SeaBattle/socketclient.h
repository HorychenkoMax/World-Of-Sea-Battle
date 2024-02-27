#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <QObject>
#include <QTcpSocket>

class SocketClient : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *socket;
    bool isMyTurn = false;

    void connectAll();
public:
    explicit SocketClient();
    explicit SocketClient(QTcpSocket *socket, bool isMyTurn);
    SocketClient(const SocketClient &client);
    void send(const QString &data);
    void run(const QString &host, qint32 port);

    bool getIsMyTurn() const;

private slots:
    void connected();
    void disconnected();
    void readyRead();


signals:
    void connectedToHost();
    void readFromOponent(const QString &string);
};

#endif // SOCKETCLIENT_H
