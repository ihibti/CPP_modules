#ifndef WEAPON_HPP
#define WEAPON_HPP
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
	void setType(const std::string& _type);
	Weapon(const std::string &type);
	~Weapon();
};
#endif