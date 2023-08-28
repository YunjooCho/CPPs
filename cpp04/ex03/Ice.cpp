/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:48:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 21:49:22 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
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

Ice::Ice(const Ice& Ice)
{
	std::cout << "Ice Copy constructor called" << std::endl;
	*this = Ice;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}