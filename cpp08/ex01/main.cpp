/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:15:32 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/06 19:15:10 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << std::endl;
	std::vector<int> test;
	for (int i = 0; i < 10000; ++i) {
		test.push_back(i);
	}
	sp.addNumbers(test);
	std::vector<int> result = sp.getVectors();
	for (int i = 9990; i < 10000; ++i) {
		std::cout << result[i] << std::endl;
	}
}