/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:43:40 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/07 11:43:45 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

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