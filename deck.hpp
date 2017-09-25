#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "card.hpp"

using Deck = std::vector<Card>;

void printDeck(const Deck& d);

void shuffleDeck(Deck& d);

Deck makeStandardDeck();

Deck makeCombinedDeck(Deck& a, Deck& b);

#endif
