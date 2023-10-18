/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:33:03 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/18 14:56:33 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << "------------- Type : integer -------------" << std::endl;
	int	intArr[5];
	int	a = 3;
	::iter(&intArr, sizeof(intArr)/sizeof(intArr[0]), ::plus(a));

	std::cout << "------------- Type : char -------------" << std::endl;
	char	charArr[10];
	char	c = 'A';
	::iter(charArr, sizeof(charArr)/sizeof(charArr[0]), ::plus(c));

	std::cout << "------------- Type : double -------------" << std::endl;
	double	doubleArr[3];
	double	e = 3.2;
	::iter(doubleArr, sizeof(doubleArr)/sizeof(doubleArr[0]), ::plus(e));

	std::cout << "------------- Type : string -------------" << std::endl;
	std::string	stringArr[3];
	std::string testStr2 = "check";
	::iter(stringArr, sizeof(stringArr)/sizeof(stringArr[0]), testStr2.append("A"));
	return (0);
}

