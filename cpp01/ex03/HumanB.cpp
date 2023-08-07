/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:00:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/07 11:20:00 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attack with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " doesn't have any weapons" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}