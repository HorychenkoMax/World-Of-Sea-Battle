#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "windows/locationselectionwindow.h"
#include "models/connectionproperties.h"
#include "models/linkmodel.h"
#include "windows/optionswindow.h"
#include "socket/socketserver.h"
#include "windows/loadingwindow.h"
#include "models/mediaplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void enableAllBottoms();

private slots:
    void on_hostButton_clicked();

    void on_ConnectButton_clicked();

    void on_changeSkinButton_clicked();

    void on_optionButton_clicked();

    void newClient(SocketClient *client);

    void connectedToHost();

private:
    Ui::MainWindow *ui;
    LocationSelectionWindow *locationSelectionWindow = nullptr;
    OptionsWindow *optionsWindow;
    SocketServer server;
    SocketClient *client;
    LoadingWindow *loadingWindow;
    MediaPlayer *player;


    const QString BACKGROUND_PATH = ":/resources/main_window_images/mainWindowBackground.jpg";
    const QString WINDOW_ICON_PATH = ":/resources/main_window_images/windowIcon.jpg";

    void setProgramView();
    void getOptionWindow();
    void newClientAfterWaiting(SocketClient *client);
    void disableAllBottoms();
};
#endif // MAINWINDOW_H
