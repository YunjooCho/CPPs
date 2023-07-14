/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:00:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/14 15:34:39 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//Constructor
HumanA::HumanA(std::string name, Weapon& weapon)
{
	this->name = name;
	this->weapon = &weapon;
}

//Method
void	HumanA::attack(void)
{
	std::cout << this->name << " attack with their " << weapon->getType() << std::endl;
}