#include <iostream>
#include <string>
#include "card.h"

Card::Card(Suit suit, Value value)
{
    this->suit = suit;
    this->value = value;
}
Card::~Card()
{
}
void Card::print()
{
    std::string output;
    switch (this->value) {
    case Value::TWO:
        output += "Two of ";
        break;
    case Value::THREE:
        output += "Three of ";
        break;
    case Value::FOUR:
        output += "Four of ";
        break;
    case Value::FIVE:
        output += "Five of ";
        break;
    case Value::SIX:
        output += "Six of ";
        break;
    case Value::SEVEN:
        output += "Seven of ";
        break;
    case Value::EIGHT:
        output += "Eight of ";
        break;
    case Value::NINE:
        output += "Nine of ";
        break;
    case Value::TEN:
        output += "Ten of ";
        break;
    case Value::JACK:
        output += "Jack of ";
        break;
    case Value::QUEEN:
        output += "Queen of ";
        break;
    case Value::KING:
        output += "King of ";
        break;
    case Value::ACE:
        output += "Ace of ";
        break;
    }
    switch (this->suit) {
    case Suit::CLUB:
        output += "Clubs";
        break;
    case Suit::DIAMOND:
        output += "Diamonds";
        break;
    case Suit::HEART:
        output += "Hearts";
        break;
    case Suit::SPADE:
        output += "Spades";
        break;
    }
    std::cout << output << std::endl;
}
bool Card::sameSuit(Card compare)
{
    if (this->suit == compare.suit) {
        return true;
    }
    return false;
}
int Card::compareValue(Card* compare)
{
    if (this->value < compare->value) {
        return -1;
    }
    if (this->value > compare->value) {
        return 1;
    }
    return 0;
}