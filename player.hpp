#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "card.hpp"
#include "deck.hpp"

using Player = std::vector<Card>;

void printPlayer(Player p);

// Discards multiple pairs from hand. Used in initial discard round in game
void removeInitialPairs(Player& p);

// Remove a single pair from hand. After the initial discard round, there should
// only be one pair
void removePair(Player& p);

// Helper function for removeInitialPairs()
bool pairPresent(Player& p);

// Appends card to and sorts player
void addCard(Player& p, Card c);

// Deals deck old-maiden style. Unequally-sized hands legal in game
void dealDeck(Deck& deck, std::vector<Player>& players); 

void takeCard(Player& p1, Player& p2, int cardIndex);

#endif
