/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:24:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/23 17:02:06 by yunjcho          ###   ########.fr       */
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
		int				getFractionalBits(void) const;
		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float 			toFloat(void) const;
		int				toInt(void) const;
	private:
		int					fixedPointNumber;
		static const int	fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed);

#endif