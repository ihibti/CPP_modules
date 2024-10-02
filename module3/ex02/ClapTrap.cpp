/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:11 by ihibti            #+#    #+#             */
/*   Updated: 2024/10/02 11:22:31 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &n_name)
{
	this->name = n_name;
	this->attackDamage = 0;
	this->hitpoints = 10;
	this->energypoints = 10;
	std::cout << name << " ClapTrap constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &other) : hitpoints(other.hitpoints),
	energypoints(other.energypoints), attackDamage(other.attackDamage),
	name(other.name){};

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
	std::cout << name << " now has " << hitpoints << " hitpoints !\n";
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