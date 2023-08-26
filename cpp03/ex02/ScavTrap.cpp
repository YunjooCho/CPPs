/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:10:37 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/26 21:45:24 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->name = "annonymous";
	this->hitPoints = SCAV_HP;
	this->energyPoints = SCAV_EP;
	this->attackDamage = SCAV_AD;
};

ScavTrap::ScavTrap(std::string inputName) : ClapTrap(inputName)
{
	std::cout << "ScavTrap Name constructor called" << std::endl;
	this->hitPoints = SCAV_HP;
	this->energyPoints = SCAV_EP;
	this->attackDamage = SCAV_AD;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavTrap)
{
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this != &scavTrap)
	{
		this->name = scavTrap.getName();
		this->hitPoints = scavTrap.getHitPoints();
		this->energyPoints = scavTrap.getEnergyPoints();
		this->attackDamage = scavTrap.getAttackDamage();
	}
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "ScavTrap Copy constructor called" << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " : I'll be BACK..." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " \
			<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
		std::cout << "[INFO] ScavTrap " << this->name << "'s Energy Point is " \
			<< this->energyPoints << std::endl;
	}
	else
	{
		std::cout << "[ERROR] ScavTrap " << this->name << " can't Anything!" << std::endl;
		std::cout << "[ERROR] Because he has no energy point or hit point." << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "[INFO] ScavTrap " << this->name << " is Gate keeper mode now." \
			<< std::endl;
		this->energyPoints--;
		std::cout << "[INFO] ScavTrap " << this->name << "'s Energy Point is " \
			<< this->energyPoints << std::endl;
	}
	else
	{
		std::cout << "[ERROR] ScavTrap " << this->name << " can't Anything!" << std::endl;
		std::cout << "[ERROR] Because he has no energy point or hit point." << std::endl;
	}
}
