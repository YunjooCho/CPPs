/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:56:20 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 15:39:47 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "========= Create Instances ========="<<std::endl;
	ClapTrap clapTrap0;
	ClapTrap clapTrapA("Yellow");
	ClapTrap clapTrapB("Red");

	std::cout << std::endl;
	std::cout << "========= Default Constructor Instance ========="<<std::endl;
	clapTrap0.attack(clapTrapA.getName());
	clapTrapA.takeDamage(clapTrap0.getAttackDamage());
	clapTrap0.takeDamage(4);
	clapTrap0.beRepaired(1);

	std::cout << std::endl;
	std::cout << "========= Name Constructor Instances - Check attack() & takeDamage() ========="<<std::endl;
	clapTrapA.attack(clapTrapB.getName());
	clapTrapB.takeDamage(clapTrapA.getAttackDamage());
	std::cout << std::endl;
	while (clapTrapA.getEnergyPoints())
	{
		clapTrapA.attack(clapTrapB.getName());
		clapTrapB.takeDamage(clapTrapA.getAttackDamage());
	}
	clapTrapA.attack(clapTrapB.getName());

	std::cout << std::endl;
	std::cout << "========= Name Constructor Instances - Check takeDamage() & beRepaired() ========="<<std::endl;
	clapTrapA.beRepaired(6);
	clapTrapB.beRepaired(6);
	std::cout << std::endl;
	clapTrapB.takeDamage(9);
	while (clapTrapB.getEnergyPoints())
	{
		clapTrapB.beRepaired(1);
	}
	clapTrapB.beRepaired(1);

	std::cout << std::endl;
	std::cout << "========= Destroy Instances ========="<<std::endl;
	return (0);
}