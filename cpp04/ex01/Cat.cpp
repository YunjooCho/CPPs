/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:51:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/26 01:06:42 by yunjcho          ###   ########seoul.kr  */
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
	if (this->type != cat.getType())
		this->type = cat.getType();
	this->setBrain(cat.getBrain());
	return (*this);
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << this->type << " Copy constructor called" << std::endl;
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

void	Cat::setBrain(Brain* brain)
{
	Brain *newBrain = new Brain();
	for (size_t i = 0; i < 100; i++)
	{
		newBrain->setIdea(brain->getIdea(i), i);
	}
}