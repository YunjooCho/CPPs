/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:29:37 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/24 22:57:05 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base	*newInstance;
	int		rand;

	rand = std::rand() % 3;
	if (rand == 0)
	{
		std::cout << "A" << std::endl;
		newInstance = new A();
	}
	else if (rand == 1)
	{
		std::cout << "B" << std::endl;
		newInstance = new B();
	}
	else if (rand == 2)
	{
		std::cout << "C" << std::endl;
		newInstance = new C();
	}
	else
	{
		std::cout << rand << std::endl;
		newInstance = NULL;
	}
	return (newInstance);
}

void identify(Base* p);
void identify(Base& p);

int main(void)
{
	Base	*result;
	std::srand(static_cast<unsigned int>(time(NULL)));
	
	result = generate();
	return (0);
}
