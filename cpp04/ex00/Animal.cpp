/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 21:30:34 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& animal)
{
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &animal)
		this->type = animal.getType();
	return (*this);
}

Animal::Animal(const Animal& animal) : type("Animal")
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << this-> type << " : ...." << std::endl;
}