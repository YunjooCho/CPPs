/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 21:48:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 21:50:04 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure Default constructor called" << std::endl;
	this->type = "Cure"
}

Cure&	Cure::operator=(const Cure& cure)
{
	std::cout << "Cure Copy assignment operator called" << std::endl;
	this->type = std::string(cure.getType());
	return (*this);
}

Cure::Cure(const Cure& cure)
{
	std::cout << "Cure Copy constructor called" << std::endl;
	*this = cure;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}