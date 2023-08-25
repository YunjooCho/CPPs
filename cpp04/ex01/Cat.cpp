/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:51:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 20:32:26 by yunjcho          ###   ########.fr       */
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
	this->brain = cat.getBrain();
	return (*this);
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	std::cout << this->type << " Copy constructor called" << std::endl;
	*this = cat;
}

Cat::~Cat()
{
	std::cout << this->type << " Destructor called" << std::endl;
	delete brain;
}

void	Cat::makeSound(void) const
{
	std::cout << this-> type << " : Meow! " << std::endl;
}

Brain Cat::getBrain(void) const
{
	std::string	tmp[100];

	for (int i = 0; i < 100; i++)
	{
		if (!std::strcmp(tmp[i].c_str(), this->brain->getIdea(i).c_str())
		{
			tmp[i] = this->brain->getIdea(i);
		}
	}
	return (tmp);
}