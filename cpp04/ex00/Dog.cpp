/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:42:33 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 01:40:46 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << this->type << " Default constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog)
{
	std::cout << this->type << " Copy assignment operator called" << std::endl;
	if (this != &dog)
		this->type = dog.getType();
	return (*this);
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << this->type << " Copy constructor called" << std::endl;
	*this = dog;
}

Dog::~Dog()
{
	std::cout << this->type << " Destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << this-> type << " : Bow! wow!" << std::endl;
}