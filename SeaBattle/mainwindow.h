#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "maingamewindow.h"
#include "connectionproperties.h"
#include "optionswindow.h"

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

private:
    Ui::MainWindow *ui;
    MainGameWindow *mainGameWindow;
    OptionsWindow *optionsWindow;

    const QString BACKGROUND_PATH = ":/resources/main_window_images/mainWindowBackground.jpg";
    const QString WINDOW_ICON_PATH = ":/resources/main_window_images/windowIcon.jpg";

    void setProgramView();
    void getOptionWindow();
};
#endif // MAINWINDOW_H
