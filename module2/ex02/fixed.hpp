/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:23 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/19 11:39:29 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iomanip>
# include <iostream>
# include <stdint.h>
# include <string>

class Fixed
{
  private:
	int m_fixedValue;
	static const int m_fractionalBits = 8;
	static const int epsilon = 1;

  public:
	// constructeurs
	Fixed();
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &other);
	Fixed fromRawValue(int raw);
	~Fixed();
	Fixed &operator=(const Fixed &other);
	// member functions
	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
	// flux ouptut
	friend std::ostream &operator<<(std::ostream &fd, const Fixed &fixed);
	// comparison operators
	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	// arithmetic operators
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	// static membre functions  min and  max
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	// increment funtions
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);
};

#endif