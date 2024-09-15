/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:11 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/16 00:14:35 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed()
{
    m_fixedValue = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other)
{

	m_fixedValue = other.m_fixedValue;
	std::cout << "Copy constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}
Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->m_fixedValue = other.m_fixedValue;
		std::cout << "Copy assignment operator called\n";
	}
	return (*this);
}

void Fixed::setRawBits(const int raw)
{
	m_fixedValue = raw;
}

int Fixed::getRawBits() const
{
	return (m_fixedValue);
}
