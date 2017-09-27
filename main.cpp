#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <random>


void dealDeck(Deck& deck, std::vector<Player>& players); 




std::random_device rng;
std::minstd_rand prng;


int main()
{
	int numPlayers = 4;
	prng.seed(rng());

	Deck deck {makeStandardDeck()};
	shuffleDeck(deck);

	std::vector<Player> players(numPlayers);
	dealDeck(deck, players);

	std::queue<Player> gameQueue;

	for(std::vector<Player>::iterator it = players.begin(); it != players.end(); it++)
	{
		gameQueue.push(*it);
		printPlayer(*it);
	}

	char pause;
	std::cin >> pause;

	bool gameOver = false;

	Player previousPlayer(0);
	previousPlayer.push_back(Card(Ace, Spades));
	std::vector<Player>::iterator pit;

	// Remove initial pairs

	while(!gameOver)
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

// Deals deck old-maiden style. Unequally-sized hands legal in game
void dealDeck(Deck& deck, std::vector<Player>& players)
{

	//Iterator to navigate player hands (initialized to the first player)
	std::vector<Player>::iterator pit {players.begin()};

	// Loops through deck, handing out a card to one of n unique players each iteration
	for(Deck::iterator dit = deck.begin(); dit != deck.end(); dit++)
	{
		pit->push_back(*dit); // dereferences dit (a card) and pushes it to the hand of a player
		pit++; // Increments pit to the next player


		if(pit == players.end())
			pit = players.begin();
	}
}



