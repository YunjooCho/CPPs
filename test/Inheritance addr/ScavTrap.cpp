/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:10:37 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/22 19:30:50 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
	this->name = "annonymous";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	// this->printHitPoints();
	// this->printEnergyPoints();
	// this->printAttackDamage();
	printf("name : %s(%p), hitPoint : %u(%p), energyPoints : %u(%p), attackDamage : %u(%p)\n", this->name.c_str(), &this->name, this->hitPoints, &this->hitPoints, this->energyPoints, &this->energyPoints, this->attackDamage, &this->attackDamage);
};

ScavTrap::ScavTrap(std::string inputName) : ClapTrap(inputName)
{
	std::cout << "ScavTrap " << this->name << " Created now!" << std::endl;
	this->name = inputName;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	// this->printHitPoints();
	// this->printEnergyPoints();
	// this->printAttackDamage();
	printf("name : %s(%p), hitPoint : %u(%p), energyPoints : %u(%p), attackDamage : %u(%p)\n", this->name.c_str(), &this->name, this->hitPoints, &this->hitPoints, this->energyPoints, &this->energyPoints, this->attackDamage, &this->attackDamage);
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& scavTrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = scavTrap.getName();
	this->hitPoints = scavTrap.getHitPoints();
	this->energyPoints = scavTrap.getEnergyPoints();
	this->attackDamage = scavTrap.getAttackDamage();
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = scavTrap;
}

ScavTrap::~ScavTrap()
{
	// std::cout << "ScavTrap " << this->name << " : I'll be BACK..." << std::endl;
}

std::string	ScavTrap::getName(void) const
{
	printf("ScavTrap getName : %s(%p)\n", this->name.c_str(), &this->name);
	return (this->name);
}

unsigned int	ScavTrap::getHitPoints(void) const
{
	printf("ScavTrap getHitPoints : %u(%p)\n", this->hitPoints, &this->hitPoints);
	return (this->hitPoints);
}

unsigned int	ScavTrap::getEnergyPoints(void) const
{
	printf("ScavTrap getEnergyPoints : %u(%p)\n", this->energyPoints, &this->energyPoints);
	return (this->energyPoints);
}

unsigned int	ScavTrap::getAttackDamage(void) const
{
	printf("ScavTrap getAttackDamage : %u(%p)\n", this->attackDamage, &this->attackDamage);
	return (this->attackDamage);
}

void	ScavTrap::printError(void)
{
	std::cout << "[ERROR] ScavTrap " << this->name << " can't Anything!" << std::endl;
	std::cout << "[ERROR] Because he has no energy point or hit point." << std::endl;
}

void	ScavTrap::printEnergyPoints(void)
{
	printf("ScavTrap printEnergyPoints : %u(%p)\n", this->energyPoints, &this->energyPoints);
	std::cout << "[INFO] ScavTrap " << this->name << "'s Energy Point is " \
		<< this->energyPoints << std::endl;
}

void	ScavTrap::printHitPoints(void)
{
	printf("ScavTrap printHitPoints : %u(%p)\n", this->hitPoints, &this->hitPoints);
	std::cout << "[INFO] ScavTrap " << this->name << "'s Hit Point is " \
		<< this->hitPoints << std::endl;
}

void	ScavTrap::printAttackDamage(void)
{
	printf("ScavTrap printAttackDamage : %u(%p)\n", this->attackDamage, &this->attackDamage);
	std::cout << "[INFO] ScavTrap " << this->name << "'s Attack Damage is " \
		<< this->attackDamage << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " \
			<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
		this->printEnergyPoints();
	}
	else
		this->printError();
}

void	ScavTrap::guardGate(void)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "[INFO] ScavTrap " << this->name << " is Gate keeper mode now." \
			<< std::endl;
		this->energyPoints--;
		this->printEnergyPoints();
	}
	else
		this->printError();
}