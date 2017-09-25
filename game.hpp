#ifndef GAME_HPP
#define GAME_HPP

#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include <stack>
#include <queue>

using Pile = std::stack<Card>;

struct Options
{
	int numDecks = 1;
	bool aceHigh = true;
	int numSacrafice = 1;
	bool negotiableSacrafice = false;
};


struct Game
{
	Options options;
	Deck deck;
	Player p1;
	Player p2;
	Pile pile;
	int turn;
};

void dealDeck(Deck& d, Player& p1, Player& p2);

void givePile(Player& p);

#endif