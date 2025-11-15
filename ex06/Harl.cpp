#include "Harl.hpp"
#include <iostream>

Harl::Harl(){}

Harl::~Harl(){}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-special-ketchup burger. ";
	std::cout << "I really do!";
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger! If you did, ";
	std::cout << "I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I’ve been coming for years, ";
	std::cout << "whereas you started working here just last month.";
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.";
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	PtrComplain p;

	p = NULL;
	if (level.empty())
		return ;
	if (level.compare("debug") == 0)
		p = &Harl::debug;
	if (level.compare("info") == 0)
		p = &Harl::info;
	if (level.compare("warning") == 0)
		p = &Harl::warning;
	if (level.compare("error") == 0)
		p = &Harl::error;
	if (p)
		(this->*p)();
}

Harl::Param paramToCode(std::string param)
{
	if (param.compare("debug") == 0 || param.compare("DEBUG") == 0)
		return Harl::Debug;
	if (param.compare("info") == 0 || param.compare("INFO") == 0)
		return Harl::Info;
	if (param.compare("warning") == 0 || param.compare("WARNING") == 0)
		return Harl::Warning;
	if (param.compare("error") == 0 || param.compare("ERROR") == 0)
		return Harl::Error;
	return Harl::Unknown;
}

void	Harl::filter(std::string param)
{
	Param p = paramToCode(param);

	switch (p)
	{
		case Debug:
			this->complain("debug");
			std::cout << std::endl;
			[[fallthrough]];
		case Info:
			this->complain("info");
			std::cout << std::endl;
			[[fallthrough]];
		case Warning:
			this->complain("warning");
			std::cout << std::endl;
			[[fallthrough]];
		case Error:
			this->complain("error");
			std::cout << std::endl;
			break ;
		case Unknown:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
