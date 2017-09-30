#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <random>

int randomIndex(int upperBound);
void printQueue(std::deque<Player> q, int numPlayers);


std::random_device rng;
std::minstd_rand prng;


int main()
{

	int numPlayers = 4;
	int numTurns = 0;
	Player pCopy;

	prng.seed(rng());

	Deck deck {makeStandardDeck()};
	std::vector<Player> players(numPlayers);

	shuffleDeck(deck);
	dealDeck(deck, players);

	std::deque<Player> gameQueue;
	for(std::vector<Player>::iterator it = players.begin(); it != players.end(); it++)
	{
		removeInitialPairs(*it);
		gameQueue.push_back(*it);
	}



	while(gameQueue.size() > 1)
	{
		numTurns++;

		pCopy = gameQueue.front();
		gameQueue.pop_front();

		int index = randomIndex(gameQueue.back().size());

		takeCard(pCopy, gameQueue.back(), index);
		if(gameQueue.back().size() == 0)
		{
			gameQueue.pop_back();
		}

		removePair(pCopy);

		if(pCopy.size() > 0)
		{
			gameQueue.push_back(pCopy);
		}
	}

	std::cout << numTurns << std::endl;
	return 0;
}


int randomIndex(int upperBound)
{
	std::uniform_int_distribution<> d(0, upperBound - 1);

	return d(prng);
} 








