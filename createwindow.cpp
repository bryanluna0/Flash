#include "createwindow.h"
#include <QLineEdit>
#include <QBoxLayout>
#include <QLabel>
#include <QPushButton>

CreateWindow::CreateWindow(std::vector<Deck>& decks)
{
    createWindow = new QWidget;

    auto outerLayout = new QVBoxLayout(createWindow);

    auto titleLabel = new QLabel("Choose a deck");
    outerLayout->addWidget(titleLabel);

    auto innerLayout = new QHBoxLayout;
    outerLayout->addLayout(innerLayout);

    deckSelector = new QComboBox;
    innerLayout->addWidget(deckSelector);

    newDeckButton = new QPushButton("New deck");
    innerLayout->addWidget(newDeckButton);

    auto text = new QLineEdit;
    outerLayout->addWidget(text);

    auto write = new QPushButton("Write");
    outerLayout->addWidget(write);

    // connect(newDeckButton, &QPushButton::pressed,
    //         [&](){decks.push_back(Deck d);});

    createWindow->show();
}
