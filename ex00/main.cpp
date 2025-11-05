#include "Zombie.h"

int	main()
{
	std::cout << "Creating new Zombie" << std::endl;
	Zombie *zombie_a = newZombie("Jimmy Zombie");

	std::cout << "Creating random chump" << std::endl;
	randomChump("Brandon Random");
	
	std::cout << "New Zombie attacking" << std::endl;
	zombie_a->announce();

	delete zombie_a;

	return (0);
}
