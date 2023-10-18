/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:33:03 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/18 16:18:23 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::cout << "------------- Type : integer -------------" << std::endl;
	int	intArr[5];
	int	a = 3;
	::iter(intArr, sizeof(intArr)/sizeof(intArr[0]), plusOne<int>(a));

	std::cout << "------------- Type : char -------------" << std::endl;
	char	charArr[10];
	char	b = 'A';
	::iter(charArr, sizeof(charArr)/sizeof(charArr[0]), plusOne<char>(b));

	std::cout << "------------- Type : double -------------" << std::endl;
	double	doubleArr[3];
	double	c = 3.234;
	::iter(doubleArr, sizeof(doubleArr)/sizeof(doubleArr[0]), plusOne<double>(c));

	std::cout << "------------- Type : string -------------" << std::endl;
	std::string	stringArr[3];
	std::string testStr = "check";
	::iter(stringArr, sizeof(stringArr)/sizeof(stringArr[0]), testStr.append("A"));

	return (0);
}

