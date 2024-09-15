#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
					"ketchup burger.I really do !\n";
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
					"enough bacon in my burger ! If you did,"
					" I wouldn’t be asking for more !\n";
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming"
					"for years whereas you started working here since last month.\n";
}

void Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n";
}

Harl::Harl()
{
	m_karandeep[0] = "DEBUG";
	m_karandeep[1] = "INFO";
	m_karandeep[2] = "WARNING";
	m_karandeep[3] = "ERROR";
	m_new_t[0] = &Harl::debug;
	m_new_t[1] = &Harl::info;
	m_new_t[2] = &Harl::warning;
	m_new_t[3] = &Harl::error;
}

void Harl::complain(std::string level)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!level.compare(m_karandeep[i]))
		{
			switch (i)
			{
			case 0:
				(this->*m_new_t[i++])();
			case 1:
				(this->*m_new_t[i++])();
			case 2:
				(this->*m_new_t[i++])();
			case 3:
				(this->*m_new_t[i])();
				break ;
			}
			return ;
		}
		i++;
	}
	std::cout << "no message similar\n";
}
