/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:51:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 13:16:43 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << this->type << " Default constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& cat)
{
	std::cout << this->type << " Copy assignment operator called" << std::endl;
	if (this->type != cat.getType())
		this->type = cat.getType();
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
}

void	Cat::makeSound(void) const
{
	std::cout << this-> type << " : Meow! " << std::endl;
}