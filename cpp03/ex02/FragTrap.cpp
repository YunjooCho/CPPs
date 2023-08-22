/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:53:20 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/22 20:19:57 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->name = "annonymous";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->printHitPoints();
	this->printEnergyPoints();
	this->printAttackDamage();
};

FragTrap::FragTrap(std::string inputName) : ClapTrap(inputName)
{
	std::cout << "FragTrap " << this->name << " Created now!" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	this->printHitPoints();
	this->printEnergyPoints();
	this->printAttackDamage();
}

FragTrap&	FragTrap::operator=(const FragTrap& fragTrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = fragTrap.getName();
	this->hitPoints = fragTrap.getHitPoints();
	this->energyPoints = fragTrap.getEnergyPoints();
	this->attackDamage = fragTrap.getAttackDamage();
	return (*this);
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fragTrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " : I'll be BACK..." << std::endl;
}

void	FragTrap::printError(void)
{
	std::cout << "[ERROR] FragTrap " << this->name << " can't Anything!" << std::endl;
	std::cout << "[ERROR] Because he has no energy point or hit point." << std::endl;
}

void	FragTrap::printEnergyPoints(void)
{
	std::cout << "[INFO] FragTrap " << this->name << "'s Energy Point is " \
		<< this->energyPoints << std::endl;
}

void	FragTrap::printHitPoints(void)
{
	std::cout << "[INFO] FragTrap " << this->name << "'s Hit Point is " \
		<< this->hitPoints << std::endl;
}

void	FragTrap::printAttackDamage(void)
{
	std::cout << "[INFO] FragTrap " << this->name << "'s Attack Damage is " \
		<< this->attackDamage << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "[INFO] FragTrap " << this->name << " request a high five." \
			<< std::endl;
		this->energyPoints--;
		this->printEnergyPoints();
	}
	else
		this->printError();
}