/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:45:15 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 00:41:54 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria Default constructor called" << std::endl;
	this->type = "";
}

AMateria&	AMateria::operator=(const AMateria& aMateria)
{
	std::cout << "AMateria Copy assignment operator called" << std::endl;
	this->type = std::string(aMateria.getType());
	return (*this);
}

AMateria::AMateria(const AMateria& AMateria)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = AMateria;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}
