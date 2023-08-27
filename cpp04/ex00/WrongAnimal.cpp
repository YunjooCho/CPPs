/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 01:41:28 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& animal)
{
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &animal)
		this->type = animal.getType();
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal) : type("WrongAnimal")
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = animal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this-> type << " : ...." << std::endl;
}