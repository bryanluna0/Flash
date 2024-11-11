#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include <QWidget>

class CreateWindow : public QWidget
{
    Q_OBJECT

public:
    CreateWindow();

private:
    QWidget* createWindow;
};

#endif // CREATEWINDOW_H
