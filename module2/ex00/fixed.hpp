/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihibti <ihibti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:05:23 by ihibti            #+#    #+#             */
/*   Updated: 2024/09/16 00:07:22 by ihibti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXEDPOINT_HPP
# define FIXEDPOINT_HPP

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
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
    int getRawBits( void ) const;
    void setRawBits(int const raw);
};

#endif
