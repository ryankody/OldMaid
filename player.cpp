#include "player.hpp"

void printPlayer(Player p)
{
	for(Player::iterator it = p.begin(); it < p.end(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << '\n';
}


void removeInitialPairs(Player& p)
{

	while(pairPresent(p))
	{
		removePair(p);
	}

}

void removePair(Player& p)
{
	for(Player::iterator it = p.begin(); it != p.end() - 1; it++)
	{
		if(it->rank == (it + 1)->rank)
		{
			p.erase(it, it + 2); // Erases the matching cards
			break;
		}
	}

}

bool pairPresent(Player& p)
{
	for(Player::iterator it = p.begin(); it != p.end() - 1; it++)
	{
		if(it->rank == (it + 1)->rank)
			return true;
	}

	return false;
}

void addCard(Player& p, Card c)
{
	p.push_back(c);
	std::sort(p.begin(), p.end());
}

void dealDeck(Deck& deck, std::vector<Player>& players)
{
	//Iterator to navigate player hands (initialized to the first player)
	std::vector<Player>::iterator pit {players.begin()};

	// Loops through deck, handing out a card to one of n unique players each iteration
	for(Deck::iterator dit = deck.begin(); dit != deck.end(); dit++)
	{
		addCard(*pit, *dit); // *pit == a player, *dit == a card
		pit++; // Increments pit to the next player


		if(pit == players.end())
			pit = players.begin();
	}
}