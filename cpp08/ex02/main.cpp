/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 14:35:27 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/09 18:58:11 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "---------- MutantStack Test ----------" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl; //17

	mstack.pop();

	std::cout << mstack.size() << std::endl; // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;	
	--it;
	int	i = 0;
	while (it != ite) //stack이 비어있지 않으면
	{
		std::cout << "MutantStack[" << i << "]: " <<  *it << std::endl;
		++it;
		++i;
	}

	std::cout << std::endl;
	std::cout << "---------- std::stack Test - Use Copy Constructor ----------" << std::endl;
	std::stack<int> s(mstack);
	i = 0;
	while (!s.empty())
	{
		// std::cout << s[i] << std::endl; // 컴파일 에러
		std::cout << "Stack[" << i << "]: " << s.top() << std::endl;
		s.pop();
		++i;
	}

	std::cout << std::endl;
	std::cout << "---------- std::list Test----------" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl; //17

	lst.pop_back();

	std::cout << lst.size() << std::endl; // 1

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();

	++it2;
	--it2;
	i = 0;
	while (it2 != ite2) //stack이 비어있지 않으면
	{
		std::cout << "MutantStack[" << i << "]: " <<  *it2 << std::endl;
		++it2;
		++i;
	}
	return 0;
}