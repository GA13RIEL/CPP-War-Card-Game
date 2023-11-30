#pragma once

#include <random>
#include "deck.h"

static std::random_device rd;
static std::mt19937 rng(rd());
Deck::Deck()
{
    for (int suit = Card::Suit::CLUB; suit <= Card::Suit::SPADE; suit++) {
        for (int value = Card::Value::TWO; value <= Card::Value::ACE; value++) {
            Card* card = new Card((Card::Suit)suit, (Card::Value)value);
            this->full_deck.push_back(card);
        }
    }
}
Deck::~Deck()
{
    for (int x = 0; x < this->full_deck.size(); x++) {
        delete this->full_deck[x];
    }
}
void Deck::shuffle()
{
    while (this->draw_deck.size() > 0) {
        this->draw_deck.pop();
    }
    std::shuffle(this->full_deck.begin(), this->full_deck.end(), rng);
    for (int x = 0; x < this->full_deck.size(); x++) {
        this->draw_deck.push(this->full_deck[x]);
    }
}
Card* Deck::draw()
{   
    Card* draw_card = NULL;
    if (this->draw_deck.empty()) {
        return draw_card;
    }
    draw_card = this->draw_deck.top();
    this->draw_deck.pop();
    return draw_card;
}


