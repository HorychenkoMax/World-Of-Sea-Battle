#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "windows/locationselectionwindow.h"
#include "models/connectionproperties.h"
#include "windows/optionswindow.h"
#include "socket/socketserver.h"
#include "windows/loadingwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

    const QString BACKGROUND_PATH = ":/resources/main_window_images/mainWindowBackground.jpg";
    const QString WINDOW_ICON_PATH = ":/resources/main_window_images/windowIcon.jpg";

    void setProgramView();
    void getOptionWindow();
};
#endif // MAINWINDOW_H
