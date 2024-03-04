#ifndef LOADINGWINDOW_H
#define LOADINGWINDOW_H


#include <QWidget>
#include <functional>
#include <QCloseEvent>
#include "scenes/loadingscene.h"

using Function=std::function<void(void)>;

namespace Ui {
class LoadingWindow;
}

class LoadingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingWindow(Function func = [](){}, QWidget *parent = nullptr);
    ~LoadingWindow();

private:
    Ui::LoadingWindow *ui;
    Function func;
    LoadingScene *loadingScene;

    void closeEvent(QCloseEvent *event) override;
    void setBackground();
};

#endif // LOADINGWINDOW_H
