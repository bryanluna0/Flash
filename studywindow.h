/* The specification file for the class of the study window.
 * This window will be used to study the cards of the
 * various decks the user may have created.
 *
 */

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
