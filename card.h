/* The specification file for the class of Card objects.
 * Cards are made up of two parts: a front and back side.
 * They also have a value for priority.
 * This class has various getters and setters for these values.
 *
 */

#ifndef CARD_H
#define CARD_H

#include <string>

// Card class
class Card
{
private:
    // Member variables storing values on front and back of a card
    std::string front;
    std::string  back;

    // Variable holding the value of the card: used for priority reasons
    double      value;

public:
    // Default constructor
    Card();

    // Constructor with values
    Card(const std::string& front, const std::string& back);

    // Getter functions
    std::string  getFront() const;
    std::string  getBack()  const;
    double       getValue() const;

    // Setter functions
    void setFront(const std::string& front);
    void setBack(const std::string& back);
    void setValue(const double value);

    // // print front and back of card
    // void print() const;

    // Operator used to compare Cards based on value
    bool operator<(const Card& other) const;

    // Operator used to compare cards based on equality of front and back
    bool operator==(const Card& other) const;

};

#endif // CARD_H
