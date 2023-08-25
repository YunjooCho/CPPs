/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:09:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 20:09:05 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

void	_leaks()
{
	system("leaks a.out");
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Animal	*animals[10];
	Brain	*brain = new Brain();

	atexit(_leaks);
	for (int i = 0; i < 10; i++)
	{
		Animal *tmp;
		if (i >= 0 && i <= 4)
			tmp = new Cat();
		else
			tmp = new Dog();
		animals[i] = tmp;
	}
	for (int i = 0; i < 10; i++)
	{
		animals[i]->getType();
		delete animals[i];
	}
	return (0);
}