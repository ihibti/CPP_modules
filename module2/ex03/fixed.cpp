/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:11 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/19 16:57:50 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed()
{
	m_fixedValue = 0;
}

Fixed::Fixed(const Fixed &other)
{
	m_fixedValue = other.m_fixedValue;
}

Fixed::~Fixed()
{
}
Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->m_fixedValue = other.m_fixedValue;
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
	m_fixedValue = raw;
}

Fixed::Fixed(const float raw)
{
	m_fixedValue = static_cast<int>(roundf(raw * (1 << m_fractionalBits)));
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
	return (this->getRawBits() != other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
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

	ret.m_fixedValue = this->m_fixedValue - other.m_fixedValue;
	return (ret);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	int resultValue = (m_fixedValue * other.m_fixedValue);
	return (Fixed(resultValue));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.m_fixedValue == 0)
	{
		std::cerr << "Division by zero";
	}
	int resultValue = (m_fixedValue) / other.m_fixedValue;
	return (Fixed(resultValue));
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

Fixed &Fixed::operator++()
{
	m_fixedValue += epsilon;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	m_fixedValue += epsilon;
	return (temp);
}

Fixed &Fixed::operator--()
{
	m_fixedValue -= epsilon;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	m_fixedValue -= epsilon;
	return (temp);
}

Fixed Fixed::abs() const
{
	Fixed ret;
	if (this->m_fixedValue < 0)
		ret.m_fixedValue = -1 * (this->m_fixedValue);
	else
		ret.m_fixedValue = this->m_fixedValue;
	return (ret);
}
