/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:00:13 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/11 17:25:14 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *zombieArray;

	zombieArray = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombieArray[i].setName(name + std::to_string(i + 1));
	}
	return (zombieArray);
}