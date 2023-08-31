/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:42:33 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/31 14:28:51 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << this->type << " Default constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& dog)
{
	std::cout << this->type << " Copy assignment operator called" << std::endl;
	if (this != &dog)
	{
		this->type = dog.getType();
		*(this->brain) = *(dog.brain);
	}
	return (*this);
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	std::cout << this->type << " Copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = dog;
}

Dog::~Dog()
{
	delete brain;
	std::cout << this->type << " Destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << this-> type << " : Bow! wow! " << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (this->brain);
}

void	Dog::setBrain(Brain* _brain)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->brain->setIdea(_brain->getIdea(i), i);
	}
}