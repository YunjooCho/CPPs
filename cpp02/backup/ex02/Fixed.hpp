/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:24:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/16 20:49:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int _fixedPointNumber);
		Fixed(const float _fixedPointNumber);
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed&			operator=(const Fixed &fixed);
		bool			operator>(const Fixed &fixed) const;
		bool			operator<(const Fixed &fixed) const;
		bool			operator>=(const Fixed &fixed) const;
		bool			operator<=(const Fixed &fixed) const;
		bool			operator==(const Fixed &fixed) const;
		bool			operator!=(const Fixed &fixed) const;
		Fixed			operator+(const Fixed &fixed) const;
		Fixed			operator-(const Fixed &fixed) const;
		Fixed			operator*(const Fixed &fixed) const;
		Fixed			operator/(const Fixed &fixed) const;
		Fixed&			operator++(void);
		Fixed&			operator--(void);
		Fixed			operator++(int);
		Fixed			operator--(int);
		int				getFractionalBits(void) const;
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float 			toFloat(void) const;
		int				toInt(void) const;
		static Fixed&	min(Fixed &fixed1, Fixed &fixed2)
		{
			return (fixed1 > fixed2 ? fixed1 : fixed2);
		}
		static const Fixed&	min(const Fixed &fixed1, const Fixed &fixed2)
		{
			return (fixed1 > fixed2 ? fixed1 : fixed2);
		}
		static Fixed&	max(Fixed &fixed1, Fixed &fixed2)
		{
			return (fixed1 < fixed2 ? fixed2 : fixed1);
		}
		static const Fixed&	max(const Fixed &fixed1, const Fixed &fixed2)
		{
			return (fixed1 < fixed2 ? fixed2 : fixed1);
		}
	private:
		int					fixedPointNumber;
		static const int	fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed);

#endif

