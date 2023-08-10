/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:55:46 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/10 14:43:41 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

void	meetEof(void)
{
	if (std::cin.eof()) 
	{
		clearerr(stdin);
		std::cin.clear();
	}
}

int main(void)
{
	int			N;
	std::string	name;
	Zombie		*array;

	std::cout << "Enter the number of zombies you want to create : " << std::endl;
	std::cin >> N;
	meetEof();
	std::cin.ignore(10000, '\n');
	std::cout << "Enter the name of zombies : " << std::endl;
	std::getline(std::cin, name);
	meetEof();
	std::cin.clear();
	array = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		array[i].announce();
	}
	delete[] array;
	return (0);
}