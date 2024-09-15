#ifndef HARL_HPP
# define HARL_HPP
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <string>

class Harl
{
  private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	typedef void (Harl::*tableau)();
	tableau m_new_t[4];
	std::string m_karandeep[4];

  public:
	void complain(std::string level);
	Harl();
};

#endif