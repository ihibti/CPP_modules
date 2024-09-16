/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:23 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/16 13:45:15 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iomanip>
# include <iostream>
# include <string>

class Fixed
{
  private:
	int m_fixedValue;
	static const int m_fractionalBits;

  public:
	Fixed();
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed(const Fixed &other);
	int toInt(void)const;
	float toFloat(void)const;
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	friend std::ostream &operator<<(std::ostream &fd, const Fixed &fixed);
};

#endif
