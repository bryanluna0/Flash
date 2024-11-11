#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QWindow>

class CreateWindow : public QWindow
{
    Q_OBJECT

public:
    CreateWindow();

private:
    QWindow* createWindow;
};

#endif // CREATEWINDOW_H
