#pragma once

#include <string>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		typedef void (Harl::*ptrComplain)(void);

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
