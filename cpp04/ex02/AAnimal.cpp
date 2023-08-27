/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:25:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 02:40:50 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << this->type << " Default constructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& animal)
{
	std::cout << this->type << " Copy assignment operator called" << std::endl;
	if (this != &animal)
		this->type = animal.getType();
	return (*this);
}

AAnimal::AAnimal(const AAnimal& animal) : type("AAnimal")
{
	std::cout << this->type << " Copy constructor called" << std::endl;
	*this = animal;
}

AAnimal::~AAnimal()
{
	std::cout << this->type << " Destructor called" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}