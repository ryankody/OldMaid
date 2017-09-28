#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <random>


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
		gameQueue.push(*it);
	}

	while(gameQueue.size() != 1) // Game ends when only one player is left
	{
		// Make copy of p(n)

		// Pop p(n) from gameQueue

		// p(n - 1) offers deck to p(n)

		// Check for pairs... delete pairs if found

		// if no card, do not requeue

		// otherwise, push p(n) to back

		// next
	}

	return 0;
}





