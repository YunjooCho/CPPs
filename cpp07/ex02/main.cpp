/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:04:15 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/28 21:15:29 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	std::cout << "---------- Subject TestCase ----------" << std::endl;
	int	*a = new int();

	*a = 42;
	std::cout << "a : " << *a << std::endl;


	std::cout << "---------- Out Of Range Exception ----------" << std::endl;
	Array<int>	intArr(7);
	int tmp = intArr[4];
	std::cout << "intArr[4] : " << tmp << std::endl;

	std::cout << "---------- No Out Of Range Exception ----------" << std::endl;
	Array<int>	intArr2(3);
	int tmp2 = intArr2[0];
	std::cout << "intArr2[2] : " << tmp2 << std::endl;

	return (0);
}