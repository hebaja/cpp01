#include "Harl.hpp"
#include <iostream>

enum Param
{
	Debug,
	Info,
	Warning,
	Error,
	Unknown
};

Param paramToCode(std::string param)
{
	Param p = Unknown;

	if (param.compare("debug") == 0)
		p = Debug;
	if (param.compare("info") == 0)
		p = Info;
	if (param.compare("warning") == 0)
		p = Warning;
	if (param.compare("error") == 0)
		p = Error;
	return (p);
}

void	filter(std::string param)
{
	Harl harl;
	Param p = paramToCode(param);

	switch (p)
	{
		case Error:
			harl.complain("error");
			[[fallthrough]];
		case Warning:
			harl.complain("warning");
			[[fallthrough]];
		case Info:
			harl.complain("info");
			[[fallthrough]];
		case Debug:
			harl.complain("debug");
			break ;
		case Unknown:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		filter(argv[1]);	
	else
		std::cout << "You must insert ONE parameter" << std::endl;
	return (0);
}
