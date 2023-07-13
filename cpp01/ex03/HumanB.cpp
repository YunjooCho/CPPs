/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:00:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/13 14:26:37 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

//Constructor
HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

//Method
void	HumanB::attack(void)
{
	std::cout << this->name << " attack with their " << weapon.getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}