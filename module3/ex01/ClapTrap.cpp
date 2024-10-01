/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:11 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/30 11:13:55 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor implementation
ClapTrap::ClapTrap()
{
	this->name = "john";
	this->attackDamage = 0;
	this->hitpoints = 10;
	this->energypoints = 10;
	std::cout << "default constructor called\n";
}
ClapTrap::ClapTrap(const std::string &n_name)
{
	this->name = n_name;
	this->attackDamage = 0;
	this->hitpoints = 10;
	this->energypoints = 10;
	std::cout << "constructor called\n";
}

// Copy constructor implementation
ClapTrap::ClapTrap(const ClapTrap &other) : hitpoints(other.hitpoints),
	energypoints(other.energypoints), attackDamage(other.attackDamage),
	name(other.name){};

// Copy assignment operator implementation
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->attackDamage = other.attackDamage;
		this->energypoints = other.energypoints;
		this->hitpoints = other.hitpoints;
		this->name = other.name;
	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap &&other) noexcept : hitpoints(other.hitpoints),
	energypoints(other.energypoints), attackDamage(other.attackDamage),
	name(std::move(other.name))
{
	other.hitpoints = 0;
	other.energypoints = 0;
	other.attackDamage = 0;
}

ClapTrap &ClapTrap::operator=(ClapTrap &&other) noexcept
{
	if (this != &other)
	{
		this->name = std::move(other.name);
		this->hitpoints = other.hitpoints;
		this->energypoints = other.energypoints;
		this->attackDamage = other.attackDamage;
		other.hitpoints = 0;
		other.energypoints = 0;
		other.attackDamage = 0;
	}
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (energypoints > 0 && hitpoints > 0)
	{
		std::cout << name << " has attacked " << target << " and has dealt " << attackDamage << " dammage\n";
		energypoints -= 1;
		return ;
	}
	if (hitpoints < 1)
		std::cout << name << " has no hitpoints left\n";
	else
		std::cout << name << " has no energy left\n";
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " has taken " << amount << " dammage !\n";
	hitpoints -= amount;
	if (hitpoints < 0)
		hitpoints = 0;
	std::cout << name << "now has " << hitpoints << " hitpoints !\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << name << " has regaigned " << amount << " hitpoints !\n";
	hitpoints += amount;
	std::cout << name << " has now " << hitpoints << " hitpoints !\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << " has been destructed\n";
}

int ClapTrap::get_ad()
{
	return (this->attackDamage);
}