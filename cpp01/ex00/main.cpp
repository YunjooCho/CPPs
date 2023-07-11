/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:41:06 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/11 15:50:35 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie *bob = new Zombie("Bob");
	bob->announce();

	Zombie *steve = newZombie("Steve");
	steve->announce();

	randomChump("Anne");

	delete bob;
	delete steve;
	return (0);
}