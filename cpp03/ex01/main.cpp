/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:12:33 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 15:43:36 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "========= Create Instances ========="<<std::endl;
	ScavTrap scavTrap0;
	ScavTrap scavTrapA("Yellow");
	ScavTrap scavTrapB("Red");
	ScavTrap scavTrapC("Blue");

	std::cout << std::endl;
	std::cout << "========= Default Constructor Instance ========="<<std::endl;
	scavTrap0.attack(scavTrapA.getName());
	scavTrapA.takeDamage(scavTrap0.getAttackDamage());
	scavTrap0.takeDamage(40);
	scavTrap0.beRepaired(1);
	
	std::cout << std::endl;
	std::cout << "========= Name Constructor Instances - Check attack() & takeDamage() ========="<<std::endl;
	scavTrapA.attack(scavTrapB.getName());
	scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	std::cout << std::endl;
	while (scavTrapA.getEnergyPoints())
	{
		scavTrapA.attack(scavTrapB.getName());
		scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	}
	scavTrapA.attack(scavTrapA.getName());

	std::cout << std::endl;
	std::cout << "========= Name Constructor Instances - Check takeDamage() & beRepaired() ========="<<std::endl;
	scavTrapA.beRepaired(6);
	scavTrapB.beRepaired(6);
	std::cout << std::endl;
	scavTrapC.takeDamage(99);
	while (scavTrapC.getEnergyPoints())
	{
		scavTrapC.beRepaired(1);
	}
	scavTrapC.beRepaired(1);

	std::cout << std::endl;
	std::cout << "========= guardGate() ========="<<std::endl;
	scavTrap0.guardGate();
	scavTrapA.guardGate();
	scavTrapB.guardGate();
	scavTrapC.guardGate();
	// ClapTrap clapTrap("Green");
	// clapTrap.guardGate();
	
	std::cout << std::endl;
	std::cout << "========= Destroy Instances ========="<<std::endl;
	return (0);
}