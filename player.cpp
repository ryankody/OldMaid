#include "player.hpp"

void printPlayer(Player p)
{
	int i = 0;

	while(!p.empty())
	{
		i++;
		std::cout << p.front() << '\n';
		p.pop();
	}

	std::cout << i;
}
