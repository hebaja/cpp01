#pragma once

#include <string>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		typedef void (Harl::*PtrComplain)(void);

	public:
		enum Param
		{
			Debug,
			Info,
			Warning,
			Error,
			Unknown
		};
		Harl();
		~Harl();
		void	complain(std::string level);
		void	filter(std::string param);
};
