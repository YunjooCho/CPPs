/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:51:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 01:41:41 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat&	WrongCat::operator=(const WrongCat& cat)
{
	std::cout << "WrongCat Copy assignment operator called" << std::endl;
	if (this != &cat)
		this->type = cat.getType();
	return (*this);
}

WrongCat::WrongCat(const WrongCat& cat) : WrongAnimal(cat)
{
	std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = cat;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << this-> type << " : Meow" << std::endl;
}