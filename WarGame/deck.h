#pragma once

#ifndef DECK_H
#define DECK_H
#include <vector>
#include <stack>
#include "card.h"
class Deck
{
public:
    Deck();
    ~Deck();
public:
    void shuffle();
    Card* draw();
protected:
    std::vector<Card*> full_deck;
    std::stack<Card*> draw_deck;
};
#endif