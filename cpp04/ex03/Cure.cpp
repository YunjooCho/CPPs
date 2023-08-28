/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:48:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 01:38:03 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	// std::cout << "Cure Default constructor called" << std::endl;
}

Cure&	Cure::operator=(const Cure& cure)
{
	// std::cout << "Cure Copy assignment operator called" << std::endl;
	this->type = std::string(cure.getType());
	return (*this);
}

Cure::Cure(const Cure& cure) : AMateria(cure)
{
	// std::cout << "Cure Copy constructor called" << std::endl;
	*this = cure;
}

Cure::~Cure()
{
	// std::cout << "Cure Destructor called" << std::endl;
}

AMateria*	Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter& target)
{
	std::cout << "Cure: \"* heals " << target.getName() << "'s wounds *\"" << std::endl;
}