#pragma once
#ifndef WAR_H
#define WAR_H
#include "deck.h"
#include "card.h"
#include <deque>
#include <vector>

class War {
public:
	War();
	~War();

public:
	void play();
	void firstPlay(std::deque<Card*> playerHand, std::deque<Card*> cpuHand);

protected:
	std::deque<Card*> p1cards;
	std::deque<Card*> cpucards;
	std::deque<Card*> tablecards;

};
#endif