#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

class Zombie
{
  private:
	std::string name;

  public:
	void announce();
	void set_name(std::string name_n);
	std::string get_name(void);
	Zombie(std::string _name);
	Zombie(void);
	~Zombie(void);
};

Zombie	*newZombie(std::string name);
