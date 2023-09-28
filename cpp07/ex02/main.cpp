/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:04:15 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/28 20:53:50 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	int	*a = new int();

	*a = 42;
	std::cout << "a : " << *a << std::endl;

	Array<int>	intArr(7);
	Array<int>	intArr2(3);

	int tmp = intArr2[4];
	std::cout << "intArr2[4] : " << tmp << std::endl;

	int tmp2 = intArr2[3];
	std::cout << "intArr2[3] : " << tmp2 << std::endl;

	return (0);
}