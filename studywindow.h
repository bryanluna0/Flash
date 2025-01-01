#ifndef STUDYWINDOW_H
#define STUDYWINDOW_H
#include <QWidget>
#include "deck.h"

class StudyWindow : public QWidget
{
public:
    StudyWindow(std::vector<Deck>& decks);

private:
    QWidget* studyWindow;
};

#endif // STUDYWINDOW_H
