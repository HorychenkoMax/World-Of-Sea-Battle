#ifndef LASTWINDOW_H
#define LASTWINDOW_H

#include <QWidget>

namespace Ui {
class LastWindow;
}

class LastWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LastWindow(QWidget *parent);
    ~LastWindow();

    void setText(bool isWin);

private slots:
    void on_mainWindowButton_clicked();

private:
    Ui::LastWindow *ui;
    QWidget *parent;

    void setBackground();
};

#endif // LASTWINDOW_H
