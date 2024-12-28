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
#include "card.h"
#include <iostream>

// Deck class
class Deck
{
private:
    // The deck is a list of card objects.
    std::vector<Card> deck;

    // Variable holding the index of the current card. Begins at -1 (No Cards)
    int currentCard;
    std::string deckName;

public:
    // Default constructor
    Deck();

    // Constructor with name
    Deck(std::string name);

    // Getters
    Card& getCurrent(); // Returns a given card
    int getCurrentIndex() const;    // Returns the current card index
    std::string getDeckName() const; // Returns the name of the deck

    // Setters
    void setDeckName(const std::string& newName); // Sets the name of the deck
    void setCurrentCardFront(const std::string& newFront); // Sets the front of the current card
    void setCurrentCardBack(const std::string& newBack); // Sets the back of the current card

    // Set currentCard to a given card
    void goNext();     // Sets next card relative to the current
    void goPrev();     // Sets previous card relative to the current
    void goFirst();

    // Prints the given side of the card
    void printCurrent() const;
    void printCurrentFront() const;
    void printCurrentBack() const;

    // Size of the deck
    int size() const;

    // Adds a given card to a deck
    void add(const Card& c);

    // // Removes all elements equal to a given card from the deck
    // void remove(const Card& c);

    // Fills a deck from a given file
    void fillFromFile(const std::string& inputFile);



};

#endif // DECK_H
