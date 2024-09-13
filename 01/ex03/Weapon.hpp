#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

class Weapon
{
  private:
	std::string type;

  public:
	std::string getType() const;
	void setType(std::string);
	Weapon(std::string type);
	~Weapon();
};