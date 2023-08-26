/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:51:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 02:43:54 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << this->type << " Default constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat)
{
	std::cout << this->type << " Copy assignment operator called" << std::endl;
	if (this != &cat)
	{
		this->type = cat.getType();
		delete this->brain;
		this->brain = new Brain(*cat.brain);
	}
	return (*this);
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << this->type << " Copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = cat;
}

Cat::~Cat()
{
	delete brain;
	std::cout << this->type << " Destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << this-> type << " : Meow! " << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (this->brain);
}

void	Cat::setBrain(Brain* _brain)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->brain->setIdea(_brain->getIdea(i), i);
	}
}