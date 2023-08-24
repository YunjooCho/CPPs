/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:24:34 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 01:55:43 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
	this->_name = "annonymous";
	this->ClapTrap::name = "annonymous_clap_name";
	this->FragTrap::hitPoints = FragTrap::getHitPoints();
	this->ScavTrap::energyPoints = ScavTrap::getEnergyPoints();
	this->FragTrap::attackDamage = FragTrap::getAttackDamage();
};

DiamondTrap::DiamondTrap(std::string _inputName) : ClapTrap(_inputName + "_clap_name"), ScavTrap(_inputName), FragTrap(_inputName)
{
	std::cout << "DiamondTrap Name constructor called" << std::endl;
	this->_name = _inputName;
    this->FragTrap::hitPoints = FragTrap::getHitPoints();
	this->ScavTrap::energyPoints = ScavTrap::getEnergyPoints();
	this->FragTrap::attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_name = diamondTrap.getName();
    this->ClapTrap::name = diamondTrap.ClapTrap::getName();
	this->FragTrap::hitPoints = diamondTrap.FragTrap::getHitPoints();
	this->ScavTrap::energyPoints = diamondTrap.ScavTrap::getEnergyPoints();
	this->FragTrap::attackDamage = diamondTrap.FragTrap::getAttackDamage();
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = diamondTrap;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " : I'll be BACK..." << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->_name << ", My GrandMother name is " << this->ClapTrap::getName() << std::endl;
}