/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:32:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/23 23:03:04 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char** av)
{
	RPN rpn;

	if (ac == 2)
	{
		try
		{
			rpn.calculate(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
		std::cout << "Error: not enough argument count." << std::endl;
	return (0);
}