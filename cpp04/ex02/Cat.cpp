/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:51:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/31 14:30:06 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
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
		*(this->brain) = *(cat.brain);
	}
	return (*this);
}

Cat::Cat(const Cat& cat) : AAnimal(cat)
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