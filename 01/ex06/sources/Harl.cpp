#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}
void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	std::string	alert[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if (level == alert[i])
		{
			switch (i)
			{
				case 0:
					this->debug();
				case 1:
					this->info();
				case 2:
					this->warning();
				case 3:
					this->error();
			}
			return ;
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return ;
}

