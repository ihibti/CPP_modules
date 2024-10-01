#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	hitpoints = 100;
	energypoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << this->name << " copy constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cout << "ScavTrap " << this->name << " assigned!\n" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destroyed!\n";
}

void ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << name << " ferociously attacks " << target << ",dealing " << attackDamage << " points of damage !\n";
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}
