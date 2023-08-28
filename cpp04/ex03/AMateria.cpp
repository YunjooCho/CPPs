/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:45:15 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 03:20:12 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "...";
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

AMateria&	AMateria::operator=(const AMateria& aMateria)
{
	if (this != &aMateria)
		this->type = std::string(aMateria.getType());
	return (*this);
}

AMateria::AMateria(const AMateria& aMateria)
{
	*this = aMateria;
}

AMateria::~AMateria()
{
}

std::string const	&AMateria::getType() const
{
	return(this->type);
}

void	AMateria::use(ICharacter& target)
{
	(void) target;
}