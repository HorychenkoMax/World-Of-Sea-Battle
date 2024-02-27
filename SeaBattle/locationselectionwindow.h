#ifndef LOCATIONSELECTIONWINDOW_H
#define LOCATIONSELECTIONWINDOW_H

#include <QMainWindow>
#include "maingamewindow.h"
#include "locationselectionscene.h"
#include "socketclient.h"

namespace Ui {
class LocationSelectionWindow;
}

class LocationSelectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LocationSelectionWindow(SocketClient *client ,QWidget *parent = nullptr);
    ~LocationSelectionWindow();

private slots:
    void on_nextButton_clicked();

    void on_rotateButton_clicked();

private:
    Ui::LocationSelectionWindow *ui;
    MainGameWindow *mainGameWindow;
    LocationSelectionScene *locationSelectionScene;
    SocketClient *client;


    void setBackground();
};

#endif // LOCATIONSELECTIONWINDOW_H
