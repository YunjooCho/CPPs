/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:26:04 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/01 17:38:08 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "===============Create Instance===============";
	Bureaucrat	anonymous1;

	try
	{
		anonymous1.increaseGrade(3);
	}
	catch(const std::exception& e)
	{
		std::cout << anonymous1 << std::endl;
	}

	Bureaucrat	anonymous2(150);
	try
	{
		anonymous2.decreaseGrade(3);
	}
	catch(const std::exception& e)
	{
		std::cout << anonymous2 << std::endl;
	}

	return (0);
}