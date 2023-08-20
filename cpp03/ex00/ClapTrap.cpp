/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:56:00 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/19 21:37:35 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string inputName) : name(inputName), hitPoints(HIT_POINT), energyPoints(ENERGY_POINT), attackDamage(ATTACK_DAMAGE) 
{
	std::cout << "ClapTrap " << this->name << " Created now!" << std::endl;
};

ClapTrap&	ClapTrap::operator=(const ClapTrap& clapTrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = clapTrap.getName();
	this->hitPoints = clapTrap.getHitPoints();
	this->energyPoints = clapTrap.getEnergyPoints();
	this->attackDamage = clapTrap.getAttackDamage();
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " : I'll be BACK..." << std::endl;
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const
{
	return (this->attackDamage);
}

void	ClapTrap::printError(void)
{
	std::cout << "[ERROR] ClapTrap " << this->name << " can't Anything!" << std::endl;
	std::cout << "[ERROR] Because he has no energy point or hit point." << std::endl;
}

void	ClapTrap::printEnergyPoints(void)
{
	std::cout << "[INFO] ClapTrap " << this->name << "'s Energy Point is " \
	<< this->energyPoints << std::endl;
}

void	ClapTrap::printHitPoints(void)
{
	std::cout << "[INFO] ClapTrap " << this->name << "'s Hit Point is " \
	<< this->hitPoints << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " \
			<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
		this->printEnergyPoints();
	}
	else
		this->printError();
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " was damaged " << amount << " points." << std::endl;
	if (this->hitPoints > this->attackDamage)
		this->hitPoints = this->hitPoints - this->attackDamage;
	else
		this->hitPoints = 0;
	this->printHitPoints();
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " repaired " << amount << " points!" << std::endl;
		this->energyPoints--;
		this->printEnergyPoints();
		if (HIT_POINT >= this->hitPoints + amount)
			this->hitPoints = this->hitPoints + amount;
		else
			this->hitPoints = HIT_POINT;
		this->printHitPoints();
	}
	else
		this->printError();
}