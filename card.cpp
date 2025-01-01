/* The implementation file for the class of Card objects.
 * Cards are made up of two parts: a front and back side.
 * They also have a value for priority.
 * This class has various getters and setters for these values.
 *
 */

#include "card.h"

// Default constructor
Card::Card()
    : front(""), back(""), value(0.5), isFront(true)
{

}

// Constructor with values
Card::Card(const std::string& front, const std::string& back)
    : front(front), back(back), value(0.5), isFront(true)
{

}

// Getter functions
std::string Card::getFront() const
{
    return front;
}

std::string Card::getBack() const
{
    return back;
}

double Card::getValue() const
{
    return value;
}

bool Card::getIsFront() const
{
    return isFront;
}

// Setter functions
void Card::setFront(const std::string& front)
{
    this->front = front;
}

void Card::setBack(const std::string& back)
{
    this->back = back;
}

void Card::setValue(const double value)
{
    this->value = value;
}

void Card::setIsFront(bool set)
{
    this->isFront = set;
}

// // print front and back of card
// void print() const
// {
//     cout
// }

// Operator used to compare Cards based on value
bool Card::operator<(const Card& other) const
{
    return this->value < other.value;
}

// Operator used to compare cards based on equality of front and back
bool Card::operator==(const Card& other) const
{
    return this->front == other.front && this->back == other.back;
}
