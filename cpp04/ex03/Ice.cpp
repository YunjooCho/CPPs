/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:48:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 22:21:41 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	std::cout << "Ice Default constructor called" << std::endl;
	this->type = "ice"
}

Ice&	Ice::operator=(const Ice& ice)
{
	std::cout << "Ice Copy assignment operator called" << std::endl;
	this->type = std::string(ice.getType());
	return (*this);
}

Ice::Ice(const Ice& ice) : AMateria(ice)
{
	std::cout << "Ice Copy constructor called" << std::endl;
	*this = ice;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

virtual void	Ice::use(ICharacter& target)
{
	std::cout << "Ice : \"* shoots an ice bolt at " << target.getName() << "*\"" << std::endl;
}