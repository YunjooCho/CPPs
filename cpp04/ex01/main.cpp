/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:09:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 01:46:45 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "================Create Instances(have a Brain) - Dog, Cat================" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "================Destroy Instances - Check Brain Instance leaks================" << std::endl;
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	std::cout << "================Create Instances Array - Half Cats, Half Dogs=================" << std::endl;
	Animal	*animals[10];

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (i >= 0 && i <= 4)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}

	std::cout << std::endl;
	std::cout << "================Destroy Instances Array=================" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "No." << i << "'s type is " << animals[i]->getType() << std::endl;
		delete animals[i];
	}
	

	std::cout << std::endl;
	std::cout << "================Check Shallow & Deep Copy=================" << std::endl;
	Cat cat1;
	cat1.getBrain()->setIdea("I like fish", 0);
	Cat cat2(cat1);
	Cat cat3;

	cat3 = cat1;

	std::cout << std::endl;
	std::cout << "================Before change Idea - Cat=================" << std::endl;
	std::cout << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << cat3.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "================After change Idea - Cat=================" << std::endl;
	cat1.getBrain()->setIdea("I like churu", 0);
	cat3.getBrain()->setIdea("I hate water", 0);
	std::cout << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << cat2.getBrain()->getIdea(0) << std::endl;
	std::cout << cat3.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	Dog dog1;
	dog1.getBrain()->setIdea("I like meat", 0);
	Dog dog2(dog1);
	Dog dog3;
	
	dog3 = dog1;

	std::cout << std::endl;
	std::cout << "================Before change Idea - Dog=================" << std::endl;
	std::cout << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << dog3.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "================After change Idea - Dog=================" << std::endl;
	dog1.getBrain()->setIdea("I like ball", 0);
	dog3.getBrain()->setIdea("I hate bad smell", 0);
	std::cout << dog1.getBrain()->getIdea(0) << std::endl;
	std::cout << dog2.getBrain()->getIdea(0) << std::endl;
	std::cout << dog3.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "================makeSound()=================" << std::endl;
	std::cout << "cat1. ";
	cat1.makeSound();
	std::cout << "cat2. ";
	cat2.makeSound();
	std::cout << "cat3. ";
	cat3.makeSound();
	std::cout << std::endl;
	std::cout << "dog1. ";
	dog1.makeSound();
	std::cout << "dog2. ";
	dog2.makeSound();
	std::cout << "dog3. ";
	dog3.makeSound();

	std::cout << std::endl;
	std::cout << "================Destroy Instances=================" << std::endl;
	return (0);
}