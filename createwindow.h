/* The specification file for the class of the create window.
 * This is the window that will be used to create new cards and decks.
 * This window is created using various QWidgets.
 *
 */

#ifndef CREATEWINDOW_H
#define CREATEWINDOW_H

#include "deck.h"
#include <QPushButton>
#include <QComboBox>
#include <QWidget>
#include <vector>

class CreateWindow : public QWidget
{
    Q_OBJECT

public:
    CreateWindow(std::vector<Deck>& decks);

private:
    QWidget* createWindow;
    QPushButton* newDeckButton;
    int selectIndex;
};

#endif // CREATEWINDOW_H
