#include "createwindow.h"
#include <QLineEdit>
#include <QVBoxLayout>

CreateWindow::CreateWindow()
{
    createWindow = new QWidget;

    auto text = new QLineEdit;
    auto q = new QVBoxLayout(createWindow);
    q->addWidget(text);


    createWindow->show();
}
