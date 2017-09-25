#include "card.hpp"
#include "deck.hpp"
#include "game.hpp"
#include "player.hpp"

#include <iostream>
#include <algorithm>
#include <random>



std::random_device rng;
std::minstd_rand prng;




int main()
{
	prng.seed(rng());

	Game g;

	g.deck = makeStandardDeck();
	shuffleDeck(g.deck);
	dealDeck(g.deck, g.p1, g.p2);


	Card p1Card;
	Card p2Card;

	while(!g.p1.empty() || !g.p2.empty())
	{
		p1Card = g.p1.front();
		g.p1.pop();

		p2Card = g.p2.front();
		g.p2.pop();

	}



	return 0;
}

