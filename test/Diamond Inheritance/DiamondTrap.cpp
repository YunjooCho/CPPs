/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:24:34 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 00:26:23 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string inputName) : ScavTrap(inputName), FragTrap(inputName)
{
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 10;
	this->attackDamage = 10;
}