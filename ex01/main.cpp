#include "Zombie.h"

int	main()
{
	int	N;
	Zombie *horde ;

	N = 4;
	horde = zombieHorde(N, "scum");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;

	return (0);
}
