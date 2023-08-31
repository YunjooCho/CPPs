/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:45:15 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/31 15:13:37 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_type = "...";
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	this->_type = type;
}

AMateria&	AMateria::operator=(const AMateria& aMateria)
{
	if (this != &aMateria)
		this->_type = std::string(aMateria.getType());
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
	return(this->_type);
}

void	AMateria::use(ICharacter& target)
{
	(void) target;
}