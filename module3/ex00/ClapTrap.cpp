/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:11 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/29 00:35:49 by ihibti           ###   ########.fr       */
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
}

// Copy constructor implementation
ClapTrap::ClapTrap(const ClapTrap &other) : attackDamage(other.attackDamage),
	name(other.name), hitpoints(other.hitpoints){};

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

// Move constructor implementation
ClapTrap::ClapTrap(ClapTrap &&other) noexcept
{
	// Move other's members to this object
}

// Move assignment operator implementation
ClapTrap &ClapTrap::operator=(ClapTrap &&other) noexcept
{
	if (this != &other)
	{
        this->attackDamage = other.attackDamage;
	}
	return (*this);
}

// Destructor implementation
ClapTrap::~ClapTrap()
{
	// Clean up any resources
}