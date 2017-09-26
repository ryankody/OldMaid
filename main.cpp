#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

#include <iostream>
#include <algorithm>
#include <string>
#include <random>


void dealDeck(Deck& deck, std::vector<Player>& players);

void dp(std::string a)
{
	std::cout << a;
}



std::random_device rng;
std::minstd_rand prng;



int main()
{
	prng.seed(rng());

	Deck deck {makeStandardDeck()};
	shuffleDeck(deck);

	std::vector<Player> players(4);
	dealDeck(deck, players);



	return 0;
}

// Deals deck old-maiden style. Unequally-sized hands legal in game
void dealDeck(Deck& deck, std::vector<Player>& players)
{
	// Iterator to naviagte deck
	Deck::iterator dit;

	//Iterator to navigate player hands (initialized to the first player)
	std::vector<Player>::iterator pit {players.begin()};


	// Loops through deck, handing out a card to one of n unique players each iteration
	for(dit = deck.begin(); dit != deck.end(); dit++)
	{
		pit->push_back(*dit); // dereferences dit (a card) and pushes it to the hand of a player
		pit++; // Increments pit to the next player

		// If the last player "around the table" is reached, the iterator goes back to the first
		if(pit == players.end())
		{
			pit = players.begin();
		}
	}
}



