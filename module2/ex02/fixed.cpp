/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:11 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/16 13:48:32 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

const int Fixed::m_fractionalBits = 8;

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
Fixed &Fixed::operator=(const Fixed &other)
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

Fixed::Fixed(const int raw)
{
	m_fixedValue = raw << m_fractionalBits;
	std::cout << "int constructor called\n";
}

Fixed::Fixed(const float raw)
{
	m_fixedValue = static_cast<int>(roundf(raw * (1 << m_fractionalBits)));
	std::cout << "Float constructor called\n";
}

int Fixed::toInt() const
{
	return (m_fixedValue >> m_fractionalBits);
}

float Fixed::toFloat() const
{
	return (static_cast<float>(m_fixedValue) / (1 << m_fractionalBits));
}
std::ostream &operator<<(std::ostream &fd, const Fixed &fixed)
{
	fd << fixed.toFloat();
	return (fd);
}
