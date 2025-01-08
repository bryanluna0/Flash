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

    auto deckSelector = new QComboBox;
    deckSelector->setEditable(true);
    deckSelector->lineEdit()->setPlaceholderText("New deck name");
    outerLayout->addWidget(deckSelector);

    QString cardTemp = "Card ";

    auto innerLayoutCard = new QHBoxLayout;
    outerLayout->addLayout(innerLayoutCard);

    auto status = new QLabel("No deck selected");
    innerLayoutCard->addWidget(status);

    auto newCard = new QPushButton("Add card");
    innerLayoutCard->addWidget(newCard);

    // auto successLabel = new QLabel;
    // innerLayout->addWidget(successLabel);

    auto innerLayoutFront = new QHBoxLayout;
    auto innerLayoutBack = new QHBoxLayout;

    outerLayout->addLayout(innerLayoutFront);
    outerLayout->addLayout(innerLayoutBack);

    auto f = new QLabel("Front: ");
    auto b = new QLabel("Back: ");

    innerLayoutFront->addWidget(f);

    auto frontText = new QLineEdit;
    innerLayoutFront->addWidget(frontText);

    innerLayoutBack->addWidget(b);

    auto backText = new QLineEdit;
    innerLayoutBack->addWidget(backText);

    auto cardEditLayout = new QHBoxLayout;
    outerLayout->addLayout(cardEditLayout);

    auto left = new QPushButton("<");
    cardEditLayout->addWidget(left);
    auto write = new QPushButton("Write");
    cardEditLayout->addWidget(write);
    auto right = new QPushButton(">");
    cardEditLayout->addWidget(right);

    for (int i = 0; i < decks.size(); i++)
    {
        if (i == 0 && decks[i].size() != 0)
        {
            decks[i].goFirst();
            Card firstCard = decks[i].getCurrent();
            status->setText(cardTemp + "1");
            frontText->setText(QString::fromStdString(firstCard.getFront()));
            backText->setText(QString::fromStdString(firstCard.getBack()));
        }
        deckSelector->addItem(QString::fromStdString(decks[i].getDeckName()));
    }

    // TODO: Add success message after creation of a new deck

    connect(deckSelector, &QComboBox::currentIndexChanged, outerLayout, [&decks, deckSelector, status, cardTemp, frontText, backText]()
    {
        status->setText(cardTemp + "1");
        std::string s = deckSelector->currentText().toStdString();
        bool make = true;
        for (auto& e: decks)
        {
            if (e.getDeckName() == s)
                make = false;
        }

        if (make)
        {
            Deck newDeck(s);
            decks.push_back(newDeck);
            frontText->clear();
            backText->clear();
        }

        if(decks[deckSelector->currentIndex()].size() > 0)
        {
            decks[deckSelector->currentIndex()].goFirst();
            Card firstCard = decks[deckSelector->currentIndex()].getCurrent();
            frontText->setText(QString::fromStdString(firstCard.getFront()));
            backText->setText(QString::fromStdString(firstCard.getBack()));

        }
        else
        {
            frontText->clear();
            backText->clear();
        }
    });

    connect(newCard, &QPushButton::pressed, innerLayoutCard, [&decks, frontText, backText, deckSelector, status, cardTemp]()
    {
        if(decks.size() > 0)
        {
            int deckIndex = deckSelector->currentIndex();
            frontText->clear();
            backText->clear();
            decks[deckIndex].add(Card("", ""));
            QString cardNumber = cardTemp + QString::fromStdString(std::to_string(decks[deckIndex].size()));
            status->setText(cardNumber);
        }
    });

    connect(write, &QPushButton::pressed, outerLayout, [&decks, frontText, backText, deckSelector, status, cardTemp]()
    {
        int deckIndex = deckSelector->currentIndex();
        if (decks[deckIndex].size() == 0)
        {
            decks[deckIndex].add(Card(frontText->text().toStdString(), backText->text().toStdString()));
        }
        else
        {
            decks[deckIndex].setCurrentCardFront(frontText->text().toStdString());
            decks[deckIndex].setCurrentCardBack(backText->text().toStdString());
        }
        frontText->clearFocus();
        backText->clearFocus();

    });

    connect(left, &QPushButton::pressed, cardEditLayout, [&decks, deckSelector, frontText, backText, status, cardTemp]()
    {
        decks[deckSelector->currentIndex()].goPrev();
        frontText->setText(QString::fromStdString(decks[deckSelector->currentIndex()].getCurrent().getFront()));
        backText->setText(QString::fromStdString(decks[deckSelector->currentIndex()].getCurrent().getBack()));
        status->setText(cardTemp + QString::fromStdString(std::to_string(decks[deckSelector->currentIndex()].getCurrentIndex() + 1)));
    });

    connect(right, &QPushButton::pressed, cardEditLayout, [&decks, deckSelector, frontText, backText, status, cardTemp]()
    {
        decks[deckSelector->currentIndex()].goNext();
        frontText->setText(QString::fromStdString(decks[deckSelector->currentIndex()].getCurrent().getFront()));
        backText->setText(QString::fromStdString(decks[deckSelector->currentIndex()].getCurrent().getBack()));
        status->setText(cardTemp + QString::fromStdString(std::to_string(decks[deckSelector->currentIndex()].getCurrentIndex() + 1)));
    });

    // TODO: make the sixe of the window fixed
    // createWindow->setFixedSize(400, 750);
    createWindow->show();
}
