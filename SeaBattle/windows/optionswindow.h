#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialog>
#include "models/connectionproperties.h"

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsWindow(QWidget *parent = nullptr);
    ~OptionsWindow();

    void init();

private slots:
    void on_saveBotton_clicked();

    void on_cancelBotton_clicked();

private:
    Ui::OptionsWindow *ui;

    void setBackground();

};

#endif // OPTIONSWINDOW_H
