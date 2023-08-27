/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:53:42 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 15:49:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "========= Create Instances ========="<<std::endl;
	DiamondTrap diamondTrap0;
	DiamondTrap diamondTrapA("Yellow");
	DiamondTrap diamondTrapB("Red");
	DiamondTrap diamondTrapC("Blue");

	std::cout << std::endl;
	std::cout << "========= Default Constructor Instance ========="<<std::endl;
	diamondTrap0.attack(diamondTrapA.getName());
	diamondTrapA.takeDamage(diamondTrap0.getAttackDamage());
	diamondTrap0.takeDamage(55);
	diamondTrap0.beRepaired(1);

	std::cout << std::endl;
	std::cout << "========= Name Constructor Instances - Check attack() & takeDamage() ========="<<std::endl;
	diamondTrapA.attack(diamondTrapB.getName());
	diamondTrapB.takeDamage(diamondTrapA.getAttackDamage());
	std::cout << std::endl;
	while (diamondTrapA.getEnergyPoints())
	{
		diamondTrapA.attack(diamondTrapB.getName());
		diamondTrapB.takeDamage(diamondTrapA.getAttackDamage());
	}
	diamondTrapA.attack(diamondTrapA.getName());

	std::cout << std::endl;
	std::cout << "========= Name Constructor Instances - Check takeDamage() & beRepaired() ========="<<std::endl;
	diamondTrapA.beRepaired(6);
	diamondTrapB.beRepaired(6);
	std::cout << std::endl;
	diamondTrapC.takeDamage(90);
	for (int i = 0; i < 10; i++)
	{
		diamondTrapC.beRepaired(1);
	}

	std::cout << std::endl;
	std::cout << "========= whoAmI() ========="<<std::endl;
	diamondTrap0.whoAmI();
	diamondTrapA.whoAmI();
	diamondTrapB.whoAmI();
	diamondTrapC.whoAmI();

	std::cout << std::endl;
	std::cout << "========= Original Functions ========="<<std::endl;
	diamondTrap0.guardGate();
	diamondTrap0.highFivesGuys();
	diamondTrapA.guardGate();
	diamondTrapA.highFivesGuys();
	diamondTrapB.guardGate();
	diamondTrapB.highFivesGuys();
	diamondTrapC.guardGate();
	diamondTrapC.highFivesGuys();

	std::cout << std::endl;
	std::cout << "========= Destroy Instances ========="<<std::endl;
	return (0);
}