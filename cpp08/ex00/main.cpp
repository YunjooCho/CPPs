/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:15:32 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/05 17:35:13 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> vec;
	int	tmpVal = 10;
	std::cout << "----------------Input Infomation----------------" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		vec.push_back(tmpVal * i);
		std::cout << "vec[" << i << "] : " << tmpVal * i << std::endl;
	}
	std::cout << "-----------------------------------------------" << std::endl;

	try
	{
		std::vector<int>::iterator iter1 = easyfind(vec, 30);
		std::cout << "vec iter1 : " << *iter1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int>::iterator iter2 = easyfind(vec, 100);
		std::cout << "vec iter2 : " << *iter2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::list<int> lis;
	std::cout << "----------------Input Infomation----------------" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		lis.push_back(tmpVal * i);
		std::cout << "list[" << i << "] : " << tmpVal * i << std::endl;
	}
	std::cout << "-----------------------------------------------" << std::endl;

	try
	{
		std::list<int>::iterator iter3 = easyfind(lis, 40);
		std::cout << "list iter3 : " << *iter3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::list<int>::iterator iter4 = easyfind(lis, 50);
		std::cout << "list iter4 : " << *iter4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::deque<int> deq;
	std::cout << "----------------Input Infomation----------------" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		deq.push_back(i);
		std::cout << "deq[" << i << "] : " << i << std::endl;
	}
	std::cout << "-----------------------------------------------" << std::endl;

	try
	{
		std::deque<int>::iterator iter5 = easyfind(deq, 4);
		std::cout << "deque iter3 : " << *iter5 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::deque<int>::iterator iter6 = easyfind(deq, 5);
		std::cout << "deque iter4 : " << *iter6 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}