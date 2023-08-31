/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:48:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/31 15:17:01 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice&	Ice::operator=(const Ice& ice)
{
	if (this != &ice)
		this->_type = ice.getType();
	return (*this);
}

Ice::Ice(const Ice& ice) : AMateria(ice) {}

Ice::~Ice() {}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}