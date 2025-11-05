#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie		*horde;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		std::string name_edit = name + char(i + '0');
		horde[i].setName(name_edit);	
	}
	return (horde);
}
