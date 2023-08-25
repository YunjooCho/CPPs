/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:42:33 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 16:16:55 by yunjcho          ###   ########.fr       */
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
	if (this->type != dog.getType())
		this->type = dog.getType();
	// for (int i = 0; i < 100; i++)
	// {
	// 	this->brain->getIdea(i) = this->brain->getIdea(i);
	// }
	this->brain = dog.brain;
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
	delete brain;
}

void	Dog::makeSound(void) const
{
	std::cout << this-> type << " : Bow! wow!" << std::endl;
}