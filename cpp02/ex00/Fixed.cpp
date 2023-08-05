/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:24:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/05 18:59:02 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixedPointNumber = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	this->fixedPointNumber = fixed.fixedPointNumber;
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	this->fixedPointNumber = fixed.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	return (this->fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	
}

Fixed::~Fixed()
{
	
}

