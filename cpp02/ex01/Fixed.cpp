/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:24:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/23 17:38:14 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPointNumber = 0;
}

Fixed::Fixed(const int _fixedPointNumber)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = _fixedPointNumber << this->fractionalBits;
}

Fixed::Fixed(const float _fixedPointNumber)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = roundf(_fixedPointNumber * (1 << this->fractionalBits));
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedPointNumber = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

int		Fixed::getFractionalBits(void) const
{
	return (this->fractionalBits);
}

int		Fixed::getRawBits(void) const
{
	return (this->fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << raw << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixedPointNumber / (1 << this->fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (roundf(toFloat()));
}

std::ostream& operator<<(std::ostream& outputStream, const Fixed& fixed)
{
	outputStream << ((float)fixed.getRawBits() / (1 << fixed.getFractionalBits()));
	return (outputStream);
}