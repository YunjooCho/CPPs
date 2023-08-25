/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:38:42 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 13:26:40 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "================Create Instances - Animal, Dog, Cat================" << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << std::endl;
	std::cout << "================getType()================" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << "================makeSound()================" << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();

	std::cout << std::endl;
	std::cout << "================Destroy Instances - Animal, Dog, Cat================" << std::endl;
	delete meta;
	delete i;
	delete j;

	std::cout << std::endl;
	std::cout << "================Create Instances - WrongAnimal, WrongCat================" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();

	std::cout << std::endl;
	std::cout << "================getType()================" << std::endl;
	std::cout << meta2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;

	std::cout << std::endl;
	std::cout << "================makeSound()================" << std::endl;
	meta2->makeSound();
	i2->makeSound();

	std::cout << std::endl;
	std::cout << "================Destroy Instances - WrongAnimal, WrongCat================" << std::endl;
	delete meta2;
	delete i2;

	return (0);
}