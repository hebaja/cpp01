#include "Harl.hpp"
#include <iostream>

int	main()
{
	Harl harl;

	void (Harl::*ptrComplain)(std::string) = &Harl::complain;

	std::cout << "[ DEBUG ]" << std::endl;
	(harl.*ptrComplain)("debug");
	std::cout << std::endl;
	std::cout << "[ INFO ]" << std::endl;
	(harl.*ptrComplain)("info");
	std::cout << std::endl;
	std::cout << "[ WARNING ]" << std::endl;
	(harl.*ptrComplain)("warning");
	std::cout << std::endl;
	std::cout << "[ ERROR ]" << std::endl;
	(harl.*ptrComplain)("error");
	std::cout << std::endl;
	
	(harl.*ptrComplain)("nonexistent");
	(harl.*ptrComplain)("");
	(harl.*ptrComplain)("     ");

	return (0);
}
