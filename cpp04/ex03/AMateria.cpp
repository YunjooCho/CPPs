/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:45:15 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 01:32:35 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	// std::cout << "AMateria Default constructor called" << std::endl;
	this->type = "";
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria&	AMateria::operator=(const AMateria& aMateria)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	if (this != &aMateria)
		this->type = std::string(aMateria.getType());
	return (*this);
}

AMateria::AMateria(const AMateria& aMateria)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = aMateria;
}

AMateria::~AMateria()
{
	// std::cout << "AMateria Destructor called" << std::endl;
}

std::string const	&AMateria::getType() const
{
	return(this->type);
}

void	AMateria::use(ICharacter& target)
{
	(void) target;
	std::cout << "AMateria use() called" << std::endl;
}