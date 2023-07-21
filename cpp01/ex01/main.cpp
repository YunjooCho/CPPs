/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:55:46 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/21 14:58:55 by yunjcho          ###   ########.fr       */
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

	std::cout << "생성할 좀비 수를 입력하세요 : " << std::endl;
	std::cin >> N;
	meetEof();
	std::cin.ignore(10000, '\n');
	std::cout << "좀비 이름을 입력하세요 : " << std::endl;
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