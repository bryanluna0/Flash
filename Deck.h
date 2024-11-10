/* The specification file for the class of Deck objects.
 * Decks are made up of Cards and stored as a list.
 * The primary methods add and remove cards from the deck.
 * We can also create a complete deck from file input given a specific input format:
 * "front < back >" with subsequent cards on new lines.
 *
*/

#ifndef DECK_H
#define DECK_H

#include <vector>
#include "../Flash/Card.h"
#include <iostream>

// Deck class
class Deck
{
private:
    // The deck is a list of card objects.
    std::vector<Card> deck;

    // Variable holding the index of the current card. Begins at 0 (First card)
    int currentCard;

public:
    // Default constructor
    Deck();

    // Returns a given card
    const Card getCurrent() const;

    // Set currentCard to a given card
    void goNext();     // Sets next card relative to the current
    void goPrev();     // Sets previous card relative to the current
    void goFirst();

    // Prints the given side of the card
    void printCurrent() const;
    void printCurrentFront() const;
    void printCurrentBack() const;

    // Adds a given card to a deck
    void add(const Card& c);

    // // Removes all elements equal to a given card from the deck
    // void remove(const Card& c);

    // Fills a deck from a given file
    void fillFromFile(const std::string& inputFile);

};

#endif // DECK_H
