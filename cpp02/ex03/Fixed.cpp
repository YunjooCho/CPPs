/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:24:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/22 16:33:52 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixedPointNumber = 0;
}

Fixed::Fixed(const int _fixedPointNumber)
{
	this->fixedPointNumber = _fixedPointNumber << this->fractionalBits;
}

Fixed::Fixed(const float _fixedPointNumber)
{
	this->fixedPointNumber = roundf(_fixedPointNumber * (1 << this->fractionalBits));
}

Fixed&	Fixed::operator=(const Fixed& fixed)
{
	this->fixedPointNumber = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	if (this->fixedPointNumber > fixed.getRawBits())
		return (1);
	else
		return (0);
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	if (this->fixedPointNumber < fixed.getRawBits())
		return (1);
	else
		return (0);
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	if (this->fixedPointNumber >= fixed.getRawBits())
		return (1);
	else
		return (0);
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	if (this->fixedPointNumber <= fixed.getRawBits())
		return (1);
	else
		return (0);
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	if (this->fixedPointNumber == fixed.getRawBits())
		return (1);
	else
		return (0);
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	if (this->fixedPointNumber != fixed.getRawBits())
		return (1);
	else
		return (0);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	Fixed temp(toFloat() + fixed.toFloat());
	return (temp);
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	Fixed temp(toFloat() - fixed.toFloat());
	return (temp);
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	Fixed temp(toFloat() * fixed.toFloat());
	return (temp);
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	if (fixed.getRawBits() != 0)
	{
		Fixed temp(toFloat() / fixed.toFloat());
		return (temp);
	}
	else
		return (0);
}

Fixed&	Fixed::operator++(void)
{
	this->fixedPointNumber++;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->fixedPointNumber--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixedPointNumber++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixedPointNumber--;
	return (temp);
}

Fixed::Fixed(const Fixed &fixed)
{
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