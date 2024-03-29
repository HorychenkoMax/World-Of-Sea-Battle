#ifndef LOCATIONSELECTIONWINDOW_H
#define LOCATIONSELECTIONWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "windows/maingamewindow.h"
#include "scenes/locationselectionscene.h"
#include "socket/socketclient.h"
#include "windows/loadingwindow.h"

namespace Ui {
class LocationSelectionWindow;
}

class LocationSelectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LocationSelectionWindow(SocketClient *client ,QWidget *parent);
    ~LocationSelectionWindow();

private slots:
    void on_nextButton_clicked();

    void on_rotateButton_clicked();

    void oponentDisconnected();

    void readFromOponent(const QString &string);

private:
    Ui::LocationSelectionWindow *ui;
    MainGameWindow *mainGameWindow;
    LocationSelectionScene *locationSelectionScene;
    SocketClient *client;
    QWidget *parent;
    bool oponentRedy = false;
    LoadingWindow *loadingWindow;


    void setBackground();
    void afterConnection();
};

#endif // LOCATIONSELECTIONWINDOW_H
