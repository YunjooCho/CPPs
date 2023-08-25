/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 13:15:34 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << this->type << " Default constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& animal)
{
	std::cout << this->type << " Copy assignment operator called" << std::endl;
	this->type = animal.getType();
	return (*this);
}

Animal::Animal(const Animal& animal) : type("Animal")
{
	std::cout << this->type << " Copy constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal()
{
	std::cout << this->type << " Destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << this-> type << " : ...." << std::endl;
}