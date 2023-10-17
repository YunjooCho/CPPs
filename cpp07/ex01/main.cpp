/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:33:03 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/17 21:51:36 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << "------------- Type : integer -------------" << std::endl;
	int	intArr[5];
	int	a = 3;
	int	b = 5;
	::iter(intArr, sizeof(intArr)/sizeof(intArr[0]), ::plus(a, b));

	std::cout << "------------- Type : char -------------" << std::endl;
	char	charArr[10];
	char	c = 'A';
	char	d = '\0';
	::iter(charArr, sizeof(charArr)/sizeof(charArr[0]), ::plus(c, d));

	std::cout << "------------- Type : double -------------" << std::endl;
	double	doubleArr[3];
	double	e = 3.2;
	double	f = 1.9;
	::iter(doubleArr, sizeof(doubleArr)/sizeof(doubleArr[0]), ::plus(e, f));

	std::cout << "------------- Type : string -------------" << std::endl;
	std::string	stringArr[3];
	std::string	g = "hi";

	for (int i = 0; i < 3; i++)
	{
		stringArr[i] = g + std::to_string(i);
		std::cout << "[Before] idx : " << i << ", value : " << stringArr[i] << std::endl;
	}
	::iter(stringArr, sizeof(stringArr)/sizeof(stringArr[0]), stringArr[0].append("A"));
	return (0);
}

