/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:56:20 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/21 16:06:22 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clapTrapA("Yellow");
	ClapTrap clapTrapB("Red");

	std::cout << std::endl;
	clapTrapA.attack(clapTrapB.getName());
	clapTrapB.takeDamage(clapTrapA.getAttackDamage());
	std::cout << std::endl;
	for (int i = HIT_POINT - 1; i > 0; i--)
	{
		clapTrapA.attack(clapTrapB.getName());
		clapTrapB.takeDamage(clapTrapA.getAttackDamage());
	}
	std::cout << std::endl;
	clapTrapA.attack(clapTrapB.getName());
	clapTrapA.beRepaired(6);

	std::cout << std::endl;
	clapTrapB.beRepaired(6);
	std::cout << std::endl;
	clapTrapB.takeDamage(8);

	for (unsigned int i = 0; i < ENERGY_POINT - 1; i++)
	{
		clapTrapB.beRepaired(2);
	}
	clapTrapB.beRepaired(2);
	std::cout << std::endl;

	return (0);
}