#include "player.hpp"

void printPlayer(Player p)
{
	for(int i = 0; i < p.size(); i++)
	{
		std::cout << p[i] << " ";
	}

	std::cout << '\n';
}
