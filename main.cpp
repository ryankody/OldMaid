#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <random>

int randomIndex(int upperBound);
void printQueue(std::queue<Player> q, int numPlayers);


std::random_device rng;
std::minstd_rand prng;


int main()
{
	int numPlayers = 4;
	prng.seed(rng());


	Deck deck {makeStandardDeck()};
	std::vector<Player> players(numPlayers);


	shuffleDeck(deck);
	dealDeck(deck, players);



	std::queue<Player> gameQueue;
	for(std::vector<Player>::iterator it = players.begin(); it != players.end(); it++)
	{
		removeInitialPairs(*it);
		gameQueue.push(*it);
	}


	Player pCopy;

	while(gameQueue.size() > 1) // Game ends when only one player is left
	{
		// Make copy of p(n)
		pCopy = gameQueue.front();

		// Pop p(n) from gameQueue
		gameQueue.pop();

		// p(n - 1) offers deck to p(n)

		int index = randomIndex(gameQueue.back().size());
		takeCard(pCopy, gameQueue.back(), index);

		// Check for pairs... delete pairs if found

		removePair(pCopy);

		// if no card, do not requeue
		if(pCopy.size() != 0)
		{
			// otherwise, push p(n) to back
			gameQueue.push(pCopy);
		}


		std::cout << '\n';
		printQueue(gameQueue, gameQueue.size());
		std::cout << gameQueue.size();

		
		// next
	}


	return 0;
}


int randomIndex(int upperBound)
{
	std::uniform_int_distribution<> d(0, upperBound - 1);

	return d(prng);
} 


void printQueue(std::queue<Player> q, int numPlayers)
{
	for(int i = 0; i < numPlayers; i++)
	{
		std::cout << "Player " << i << ": ";
		printPlayer(q.front());
		q.pop();
	}
}






