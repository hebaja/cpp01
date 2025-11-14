#include "Harl.hpp"
#include <iostream>

int	main()
{
	Harl harl;

	void (Harl::*ptrComplain)(std::string) = &Harl::complain;

	std::cout << "DEBUG: ";
	(harl.*ptrComplain)("debug");
	std::cout << "INFO: ";
	(harl.*ptrComplain)("info");
	std::cout << "WARNING: ";
	(harl.*ptrComplain)("warning");
	std::cout << "ERROR: ";
	(harl.*ptrComplain)("error");
	
	(harl.*ptrComplain)("nonexistent");
	(harl.*ptrComplain)("");
	(harl.*ptrComplain)("     ");

	return (0);
}
