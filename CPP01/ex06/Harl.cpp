#include "Harl.hpp"

Harl::Harl()
{

}
Harl::~Harl()
{

}

void Harl::_debug(void)
{
    std::cout << "I love having extra beef for my 7XL-double-cheese-triple" <<
				"-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra beef costs more money. You" <<
				" didn't put enough beef in my burger! If you did, I " <<
				"wouldn't be asking for more!" << std::endl;
}
void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra beef for free. I've" <<
				" been coming for years whereas you started working here " <<
				"since last month." << std::endl;
}
void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." <<
					std::endl;
}

void Harl::complain(std::string level)
{
    void (Harl::*levelassign[4])();
    levelassign[0] = &Harl::_debug;
    levelassign[1] = &Harl::_info;
    levelassign[2] = &Harl::_warning;
    levelassign[3] = &Harl::_error;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            (this->*levelassign[i])();
            return;
        }
    }
}