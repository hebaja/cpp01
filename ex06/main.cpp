#include "Harl.hpp"
#include <iostream>


int	main(int argc, char **argv)
{
	Harl harl;

	if (argc == 2)
		harl.filter(argv[1]);	
	else
		std::cout << "You must insert ONE parameter" << std::endl;
	return (0);
}
