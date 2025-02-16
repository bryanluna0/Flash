/* The specification file for the class of the study window.
 * This window will be used to study the cards of the
 * various decks the user may have created.
 *
 */

#include "studywindow.h"
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QRect>

StudyWindow::StudyWindow(std::vector<Deck>& decks)
{
    studyWindow = new QWidget;

    auto outerLayout = new QVBoxLayout(studyWindow);
    studyWindow->setLayout(outerLayout);

    auto innerLayout = new QHBoxLayout;
    outerLayout->addLayout(innerLayout);

    QLabel* deckNametag = nullptr;

    QComboBox* deckSelector = nullptr;

    auto cardText = new QLabel;

    auto cardBrowseLayout = new QHBoxLayout;
    outerLayout->addLayout(cardBrowseLayout);

    QPushButton* left = nullptr;
    QPushButton* flip = nullptr;
    QPushButton* right = nullptr;

    if (decks.size() == 0)
    {
        auto noDeck = new QLabel("No sets created");
        outerLayout->addWidget(noDeck);
    }
    else
    {
        cardText->setAlignment(Qt::AlignCenter);
        cardText->setStyleSheet("QLabel {background-color : SkyBlue}");
        cardText->setFixedHeight(55);
        outerLayout->addWidget(cardText);
        deckNametag = new QLabel("Set: ");
        innerLayout->addWidget(deckNametag);

        deckSelector = new QComboBox;
        innerLayout->addWidget(deckSelector);

        left = new QPushButton("<");
        cardBrowseLayout->addWidget(left);
        flip = new QPushButton("Flip");
        cardBrowseLayout->addWidget(flip);
        right = new QPushButton(">");
        cardBrowseLayout->addWidget( right);

        for(auto& e: decks)
        {
            deckSelector->addItem(QString::fromStdString(e.getDeckName()));
        }

        if (decks[0].size() > 0)
        {
            decks[0].goFirst();
            cardText->setText(QString::fromStdString(decks[0].getCurrent().getFront()));
        }
        else
        {
            auto noCards = new QLabel("This set has no cards");
            outerLayout->addWidget(noCards);
        }
    }

    connect(deckSelector, &QComboBox::currentIndexChanged, outerLayout, [&decks, deckSelector, cardText]()
    {
        decks[deckSelector->currentIndex()].goFirst();
        Card firstCard = decks[deckSelector->currentIndex()].getCurrent();
        cardText->setText(QString::fromStdString(firstCard.getFront()));
        cardText->setStyleSheet("QLabel {background-color : SkyBlue}");
    });

    connect(left, &QPushButton::pressed, cardBrowseLayout, [&decks, deckSelector, cardText]()
    {
        decks[deckSelector->currentIndex()].getCurrent().setIsFront(true);
        decks[deckSelector->currentIndex()].goPrev();
        cardText->setText(QString::fromStdString(decks[deckSelector->currentIndex()].getCurrent().getFront()));
        cardText->setStyleSheet("QLabel {background-color : SkyBlue}");
    });

    connect(flip, &QPushButton::pressed, cardBrowseLayout, [&decks, deckSelector, cardText]()
    {
        if(decks[deckSelector->currentIndex()].getCurrent().getIsFront())
        {
            decks[deckSelector->currentIndex()].getCurrent().setIsFront(false);
            cardText->setText(QString::fromStdString(decks[deckSelector->currentIndex()].getCurrent().getBack()));
            cardText->setStyleSheet("QLabel {background-color : SandyBrown}");
        }
        else
        {
            decks[deckSelector->currentIndex()].getCurrent().setIsFront(true);
            cardText->setText(QString::fromStdString(decks[deckSelector->currentIndex()].getCurrent().getFront()));
            cardText->setStyleSheet("QLabel {background-color : SkyBlue}");
        }
    });

    connect(right, &QPushButton::pressed, cardBrowseLayout, [&decks, deckSelector, cardText]()
    {
        decks[deckSelector->currentIndex()].getCurrent().setIsFront(true);
        decks[deckSelector->currentIndex()].goNext();
        cardText->setText(QString::fromStdString(decks[deckSelector->currentIndex()].getCurrent().getFront()));
        cardText->setStyleSheet("QLabel {background-color : SkyBlue}");
    });

    studyWindow->show();
}
