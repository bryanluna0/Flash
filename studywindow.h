#ifndef STUDYWINDOW_H
#define STUDYWINDOW_H
#include <QWindow>

class StudyWindow : public QWindow
{
public:
    StudyWindow();

private:
    QWindow* studyWindow;
};

#endif // STUDYWINDOW_H
