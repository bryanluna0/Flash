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
    auto status = new QLabel("No deck selected");

    outerLayout->addWidget(status);

    // TODO: MAKE MAP? TO STORE NAMES AND GET VALUES FOR THEM???
    for (auto& e: decks)
    {
        qDebug() << e.getDeckName();
        deckSelector->addItem(QString::fromStdString(e.getDeckName()));
    }

    // auto successLabel = new QLabel;
    // innerLayout->addWidget(successLabel);

    auto innerLayoutFront = new QHBoxLayout;
    auto innerLayoutBack = new QHBoxLayout;

    outerLayout->addLayout(innerLayoutFront);
    outerLayout->addLayout(innerLayoutBack);

    QString fTemp = "Front: ";
    QString bTemp = "Back: ";

    auto f = new QLabel("Front: ");
    auto b = new QLabel("Back: ");

    innerLayoutFront->addWidget(f);

    auto frontText = new QLineEdit;
    innerLayoutFront->addWidget(frontText);

    innerLayoutBack->addWidget(b);

    auto backText = new QLineEdit;
    innerLayoutBack->addWidget(backText);

    auto write = new QPushButton("Write");
    outerLayout->addWidget(write);

    // TODO: STORE THE NAMES ADDED INTO COMBOBOX AS DECK NAMES
    // TODO: Add success message after creation of a new deck
    // TODO: Currently, changing decks makes a new deck, fix that
    // connect(deckSelector, &QComboBox::currentIndexChanged, this,
    //         [=]() {/*selectIndex = deckSelector->currentIndex();*/ qDebug() << deckSelector->currentIndex(); });
    connect(deckSelector, &QComboBox::currentIndexChanged, outerLayout, [&decks, deckSelector, status, cardTemp]()
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
            qDebug() << decks[deckSelector->currentIndex()].getDeckName();
        }
    });


    connect(write, &QPushButton::pressed, outerLayout, [&decks, frontText, backText, deckSelector, f, fTemp, b, bTemp, status, cardTemp]()
    {
        int cardIndex = deckSelector->currentIndex();
        decks[cardIndex].add(Card(frontText->text().toStdString(),
        backText->text().toStdString()));
        f->setText(fTemp + frontText->text());
        b->setText(bTemp + backText->text());
        status->setText(cardTemp + QString::fromStdString(std::to_string(decks[cardIndex].size() + 1)) );
    });


    createWindow->show();
}
