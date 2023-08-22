/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:53:42 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/22 20:23:38 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	std::cout << "========= Create Instances ========="<<std::endl;
	FragTrap fragTrap0;
	FragTrap fragTrapA("Yellow");
	FragTrap fragTrapB("Red");
	FragTrap fragTrapC("Blue");
	ClapTrap clapTrap("Green");
	// ScavTrap scavTrap("White");

	std::cout << std::endl;
	std::cout << "========= Default Constructor Instance ========="<<std::endl;
	fragTrap0.attack(fragTrapA.getName());
	fragTrapA.takeDamage(fragTrap0.getAttackDamage());
	fragTrap0.takeDamage(55);
	fragTrap0.beRepaired(1);

	std::cout << std::endl;
	std::cout << "========= Name Constructor Instances - Check attack() & takeDamage() ========="<<std::endl;
	fragTrapA.attack(fragTrapB.getName());
	fragTrapB.takeDamage(fragTrapA.getAttackDamage());
	std::cout << std::endl;
	while (fragTrapA.getEnergyPoints())
	{
		fragTrapA.attack(fragTrapB.getName());
		fragTrapB.takeDamage(fragTrapA.getAttackDamage());
	}
	std::cout << std::endl;
	fragTrapA.attack(fragTrapA.getName());
	fragTrapA.beRepaired(6);
	fragTrapB.beRepaired(6);

	std::cout << std::endl;
	std::cout << "========= Name Constructor Instances - Check takeDamage() & beRepaired() ========="<<std::endl;
	fragTrapC.takeDamage(90);
	while (fragTrapC.getEnergyPoints())
	{
		fragTrapC.beRepaired(1);
	}
	fragTrapC.beRepaired(1);

	std::cout << std::endl;
	std::cout << "========= highFiveGuys() ========="<<std::endl;
	fragTrap0.highFivesGuys();
	fragTrapA.highFivesGuys();
	fragTrapB.highFivesGuys();
	fragTrapC.highFivesGuys();
	// clapTrap.highFivesGuys();
	// fragTrapC.guardGate();
	
	std::cout << std::endl;
	std::cout << "========= Destroy Instances ========="<<std::endl;
	return (0);
}