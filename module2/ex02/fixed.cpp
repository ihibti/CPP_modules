/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:11 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/18 17:42:13 by ihibti           ###   ########.fr       */
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

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->getRawBits() != other->getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other->getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other->getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other->getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other->getRawBits());
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other->getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other->getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed ret;

	ret.m_fixedValue = this->m_fixedValue + other.m_fixedValue;
	return (ret);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed ret;

	ret.m_fixedValue = this->m_fixedValue - other->m_fixedValue;
	return (ret);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	int64_t result = static_cast<int64_t>(value) * other.value;
	return (Fixed(static_cast<int32_t>(result >> fractionalBits)));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	int64_t temp = static_cast<int64_t>(this->m_fixedValue) << fractionalBits;
	return (Fixed(static_cast<int32_t>(temp / other.m_fixedValue)));
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	return (b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	return (b);
}