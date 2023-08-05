/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:24:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/05 16:02:15 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed&	operator=(const Fixed &fixed);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					fixedPointNumber;
		static const int	fractionalBits = 8;
};

#endif