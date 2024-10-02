#include"FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	hitpoints = 100;
	energypoints = 50;
	attackDamage = 20;
	std::cout << "FragTrap " << this->name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->name << " copy constructed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "FragTrap " << this->name << " assigned!\n" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destroyed!\n";
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << name << " ferociously attacks " << target << ",dealing " << attackDamage << " points of damage !\n";
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " is hanging for a high five!" << std::endl;
}