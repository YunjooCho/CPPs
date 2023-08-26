/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:56:00 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 01:28:26 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("anonnymous"), hitPoints(CLAP_HP), energyPoints(CLAP_EP), attackDamage(CLAP_AD) 
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string inputName) : name(inputName), hitPoints(CLAP_HP), energyPoints(CLAP_EP), attackDamage(CLAP_AD) 
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
};

ClapTrap&	ClapTrap::operator=(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &clapTrap)
	{
		this->name = clapTrap.getName();
		this->hitPoints = clapTrap.getHitPoints();
		this->energyPoints = clapTrap.getEnergyPoints();
		this->attackDamage = clapTrap.getAttackDamage();
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " \
			<< this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
		std::cout << "[INFO] ClapTrap " << this->name << "'s Energy Point is " \
			<< this->energyPoints << std::endl;
	}
	else
	{
		std::cout << "[ERROR] ClapTrap " << this->name << " can't Anything!" << std::endl;
		std::cout << "[ERROR] Because he has no energy point or hit point." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " was damaged " << amount << " points." << std::endl;
	if (this->hitPoints > amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
	std::cout << "[INFO] ClapTrap " << this->name << "'s Hit Point is " \
		<< this->hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " repaired " << amount << " points!" << std::endl;
		this->energyPoints--;
		std::cout << "[INFO] ClapTrap " << this->name << "'s Energy Point is " \
			<< this->energyPoints << std::endl;
		this->hitPoints += amount;
		std::cout << "[INFO] ClapTrap " << this->name << "'s Hit Point is " \
			<< this->hitPoints << std::endl;
	}
	else
	{
		std::cout << "[ERROR] ClapTrap " << this->name << " can't Anything!" << std::endl;
		std::cout << "[ERROR] Because he has no energy point or hit point." << std::endl;
	}
}