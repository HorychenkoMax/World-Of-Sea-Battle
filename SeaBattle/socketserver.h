#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#include <QObject>

class SocketServer : public QObject
{
    Q_OBJECT
public:
    explicit SocketServer(QObject *parent = nullptr);

signals:

};

#endif // SOCKETSERVER_H