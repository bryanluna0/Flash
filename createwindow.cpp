#include "createwindow.h"
#include <QBoxLayout>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

CreateWindow::CreateWindow(std::vector<Deck>& decks)
{
    createWindow = new QWidget;

    auto outerLayout = new QVBoxLayout(createWindow);

    auto titleLabel = new QLabel("Choose or create a new deck");
    outerLayout->addWidget(titleLabel);

    auto innerLayout = new QHBoxLayout;
    outerLayout->addLayout(innerLayout);

    deckSelector = new QComboBox;
    deckSelector->setEditable(true);

    // TODO: MAKE MAP? TO STORE NAMES AND GET VALUES FOR THEM???
    for (auto& e: decks)
    {
        qDebug() << e.getDeckName();
        deckSelector->addItem(QString::fromStdString(e.getDeckName()));
    }
    innerLayout->addWidget(deckSelector);

    auto successLabel = new QLabel;
    innerLayout->addWidget(successLabel);

    auto text = new QLineEdit;
    outerLayout->addWidget(text);

    auto write = new QPushButton("Write");
    outerLayout->addWidget(write);

    // TODO: STORE THE NAMES ADDED INTO COMBOBOX AS DECK NAMES
    // TODO: Add success message after creation of a new deck
    // TODO: Currently, changing decks makes a new deck, fix that
    connect(deckSelector, &QComboBox::currentIndexChanged,
            [&](){Deck newDeck; decks.push_back(newDeck); qDebug() << decks.size(); });
    // connect(deckSelector, &QComboBox::currentIndexChanged, successLabel,
    //         [&](){successLabel->setText("s"); });
    // connect(deckSelector, &QComboBox::currentIndexChanged, deckSelector, &QComboBox::clearEditText);

    createWindow->show();
}
