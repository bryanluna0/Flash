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
    QComboBox* deckSelector;
};

#endif // CREATEWINDOW_H
