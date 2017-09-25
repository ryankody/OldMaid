#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

#include <iostream>
#include <algorithm>
#include <random>



std::random_device rng;
std::minstd_rand prng;




int main()
{
	prng.seed(rng());

	return 0;
}

