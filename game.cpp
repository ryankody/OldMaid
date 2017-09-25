#include "game.hpp"

void dealDeck(Deck& d, Player& p1, Player& p2)
{
	while(!d.empty())
	{
		p1.push(d.back());
		d.pop_back();
		p2.push(d.back());
		d.pop_back();
	}
}

void givePile(Player& p)
{
	Card c { };

	while(!pile.empty())
	{
		c = pile.pop();
		p.push(c);
	}

}
