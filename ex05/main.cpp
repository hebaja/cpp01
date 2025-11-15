#include "Harl.hpp"
#include <iostream>

int	main()
{
	Harl harl;

	std::cout << "[ DEBUG ]" << std::endl;
	harl.complain("debug");
	std::cout << std::endl;
	std::cout << "[ INFO ]" << std::endl;
	harl.complain("info");
	std::cout << std::endl;
	std::cout << "[ WARNING ]" << std::endl;
	harl.complain("warning");
	std::cout << std::endl;
	std::cout << "[ ERROR ]" << std::endl;
	harl.complain("error");
	
	harl.complain("nonexistent");
	harl.complain("");
	harl.complain("     ");

	return (0);
}
