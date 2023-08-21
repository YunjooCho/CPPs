/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:12:33 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/21 20:49:15 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavTrapA("Yellow");
	ScavTrap scavTrapB("Red");
	ScavTrap scavTrapC("Blue");
	ScavTrap scavTrapD("Green");

	std::cout << std::endl;
	scavTrapA.attack(scavTrapB.getName());
	scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	while (scavTrapA.getEnergyPoints())
	{
		scavTrapA.attack(scavTrapB.getName());
		scavTrapB.takeDamage(scavTrapA.getAttackDamage());
	}
	scavTrapA.attack(scavTrapA.getName());
	scavTrapA.beRepaired(5);

	std::cout << std::endl;
	scavTrapC.takeDamage(80);
	while (scavTrapC.getEnergyPoints())
	{
		scavTrapC.beRepaired(1);
	}
	scavTrapC.beRepaired(1);

	std::cout << std::endl;
	scavTrapA.guardGate();
	scavTrapB.guardGate();
	scavTrapC.guardGate();
	scavTrapD.guardGate();
	std::cout << std::endl;
	return (0);
}