/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:53:20 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 01:30:27 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->name = "annonymous";
	this->hitPoints = FRAG_HP;
	this->energyPoints = FRAG_EP;
	this->attackDamage = FRAG_AD;
};

FragTrap::FragTrap(std::string inputName) : ClapTrap(inputName)
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	this->hitPoints = FRAG_HP;
	this->energyPoints = FRAG_EP;
	this->attackDamage = FRAG_AD;
}

FragTrap&	FragTrap::operator=(const FragTrap& fragTrap)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fragTrap)
	{
		this->name = fragTrap.getName();
		this->hitPoints = fragTrap.getHitPoints();
		this->energyPoints = fragTrap.getEnergyPoints();
		this->attackDamage = fragTrap.getAttackDamage();
	}
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

void	FragTrap::highFivesGuys(void)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "[INFO] FragTrap " << this->name << " request a high five." \
			<< std::endl;
		this->energyPoints--;
		std::cout << "[INFO] FragTrap " << this->name << "'s Energy Point is " \
			<< this->energyPoints << std::endl;
	}
	else
	{
		std::cout << "[ERROR] FragTrap " << this->name << " can't Anything!" << std::endl;
		std::cout << "[ERROR] Because he has no energy point or hit point." << std::endl;
	}
}