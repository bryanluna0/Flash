/* The implementation file for the class of Deck objects.
 * Decks are made up of Cards and stored as a list.
 * The primary methods add and remove cards from the deck.
 * We can also create a complete deck from file input given a specific input format:
 * "front < back >" with subsequent cards on new lines.
 *
*/

#include "deck.h"
#include <fstream>

// Default constuctor
Deck::Deck()
    : currentCard(-1), deckName("")
{

}

// Constructor with name
Deck::Deck(std::string name)
    : currentCard(-1), deckName(name)
{

}

// Returns the first card of the list in the deck
const Card Deck::getCurrent() const
{
    return deck[currentCard];
}

// Returns the current card index
int Deck::getCurrentIndex() const
{
    return currentCard;
}

// Returns the name of the deck
std::string Deck::getDeckName() const
{
    return deckName;
}

// Sets the name of the deck
void Deck::setDeckName(const std::string& newName)
{
    deckName = newName;
}

// Returns the next card relative to the current
void Deck::goNext()
{
    currentCard++;
    if (currentCard > deck.size() - 1)
    {
        currentCard = 0;
    }
}

// Returns the previous card relative to the current
void Deck::goPrev()
{
    currentCard--;
    if (currentCard < 0)
    {
        currentCard = deck.size() - 1;
    }
}

void Deck::goFirst()
{
    currentCard = 0;
}

// Prints the given side of the card
void Deck::printCurrent() const
{
    std::cout << deck[currentCard].getFront() << "\n";
    std::cout << deck[currentCard].getBack() << "\n";
}

void Deck::printCurrentFront() const
{
    std::cout << deck[currentCard].getFront() << "\n";
}

void Deck::printCurrentBack() const
{
    std::cout << deck[currentCard].getBack() << "\n";

}

// Adds a given card to a deck
void Deck::add(const Card& c)
{
    deck.push_back(c);
    goNext();
}

int Deck::size() const
{
    return deck.size();
}

// // Removes all elements equal to a given card from the deck
// void Deck::remove(const Card& c)
// {
//     deck.erase(c);
// }

// Fills a deck from a given file
void Deck::fillFromFile(const std::string& inputFile)
{
    std::ifstream inFile(inputFile);
    std::string front;
    std::string back;

    while (std::getline(inFile, front, '<'))
    {
        std::getline(inFile, back, '>');

        std::string stripFront = "";
        std::string stripBack = "";
        for (char c: front)
        {
            if (isalnum(c))
                stripFront += c;
        }
        for (char c: back)
        {
            if (isalnum(c))
                stripBack += c;
        }

        Card tempCard(stripFront, stripBack);
        deck.push_back(tempCard);
    }
}

