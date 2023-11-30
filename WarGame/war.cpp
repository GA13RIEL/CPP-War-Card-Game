#include "war.h"
#include "deck.h"
#include "card.h"
#include <deque>
#include <iostream>


War::War()
{
}
War::~War()
{
}

//method to play War

void War::play() {
	std::string playerName;
	std::cout << "Welcome to War! Please enter your name: ";
	std::cin >> playerName ;

	Deck gameDeck;

	gameDeck.shuffle();


	//deal out 26 cards to each player
	for (int i = 0; i < 26; i++)
	{
		p1cards.push_back(gameDeck.draw());
		cpucards.push_back(gameDeck.draw());
	}

	std::string continueGame;
	bool gameOver = false;

	while (gameOver == false) {

		do {
			firstPlay(p1cards, cpucards);

			if (p1cards.size() == 52 || cpucards.size() == 52)
				break;

			std::cout << "Would you like to continue the game? yes(y) or no(n):" << std::endl;
			std::cin >> continueGame;		//check if player wants to continue


		} while (continueGame == "yes" || continueGame == "Yes" || continueGame == "y"); //loops to another round 

		if (continueGame == "no" || continueGame == "No" || continueGame == "n") {
			std::cout <<"\n" << playerName << " has forfeited the game. Computer wins!" << std::endl;
			std::cout << playerName << " had " << p1cards.size() << " cards. Computer had " << cpucards.size() << " cards." << std::endl;
			gameOver = true;		//ends game
		}

		//checks if player/cpu has all the cards
		if (p1cards.size() == 52) { 
			std::cout << "\n" << playerName << " has all the cards. " << playerName << " wins!!!" << std::endl;
			gameOver = true;
		}

		if (cpucards.size() == 52) {
			std::cout << "\nComputer has all the cards. Computer wins!" << std::endl;
			gameOver = true;
		}
	}

	std::cout << "\nThanks for playing!" << std::endl;
		



}

void War::firstPlay(std::deque<Card*> playerHand, std::deque<Card*> cpuHand)
{
	std::deque<Card*> tablecards;	//queue for cards on table
	bool moveOver = false;

	Card* playerCard = playerHand.at(0);      // Get top cards
	Card* compCard = cpuHand.at(0);

	int pValue = playerCard->value;
	int cValue = compCard->value;

	int result = 3;			//initiate result variable

	std::cout << "\nYour card: "<< std::endl;		//print your card, then computer's
	playerHand.at(0)->print();

	std::cout << "" << std::endl;

	std::cout << "Computer's card: " << std::endl;
	cpuHand.at(0)->print();

	std::cout << "" << std::endl;

	tablecards.push_front(playerHand.at(0));		//push your card to the queue of cards on table
	playerHand.pop_front();
	tablecards.push_front(cpuHand.at(0));			//push cpu cards onto table
	cpuHand.pop_front();

	if (pValue > cValue)			//compare values
		result = 1;
	else if (pValue < cValue)
		result = -1;
	else result = 0;

	while (!moveOver) {

		// if player wins, push cards on table to back of their hand
		if (result == 1) {
			std::cout << "You won the round! " << std::endl;

			for (int i = 0; i < tablecards.size(); i++)
				playerHand.push_back(tablecards.at(i));

			while (tablecards.size() > 0) //clears table
				tablecards.clear();

			moveOver = true;
		}

		//if cpu wins, push cards on table to back of their hand
		if (result == -1) {
			std::cout << "Computer won the round! " << std::endl;

			for (int i = 0; i < tablecards.size(); i++)
				cpuHand.push_back(tablecards.at(i));

			while (tablecards.size() > 0)
				tablecards.clear();

			moveOver = true;
		}

		//if tie, draw one face down card on to table
		while (result == 0) {
			std::cout << "\nWar!!! " << std::endl;

			//first card from each is placed face down on table, popped out of each hand
			tablecards.push_back(playerHand.at(0));
			playerHand.pop_front();
			tablecards.push_back(cpuHand.at(0));
			cpuHand.pop_front();

			// next card is the card to be played 
			playerCard = playerHand.at(0);      
			compCard = cpuHand.at(0);
			pValue = playerCard->value;
			cValue = compCard->value;

			std::cout << "\nYour card: " << std::endl;
			playerHand.at(0)->print();					//print cards going against each other

			std::cout << "" << std::endl;

			std::cout << "Computer's card: " << std::endl;
			cpuHand.at(0)->print();

			std::cout << "" << std::endl;

			//place cards on table, pop them out of each players hands
			tablecards.push_back(playerHand.at(0));
			playerHand.pop_front();
			tablecards.push_back(cpuHand.at(0));
			cpuHand.pop_front();

			// check for what to do with the result, repeat loop if necessary (if result is 0, war again)
			if (pValue > cValue)
				result = 1;
			else if (pValue < cValue)
				result = -1;
			else result = 0;

		}
	}
			//clears cards on the table
			while (tablecards.size() > 0)
				tablecards.clear();

			swap(p1cards, playerHand);  //swap used to update player and computer's cards to their new hand.
			swap(cpucards, cpuHand);
}
	
