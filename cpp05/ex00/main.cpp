/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:26:04 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 17:29:49 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "=============== GradeTooHighException ===============" << std::endl;
	Bureaucrat	anonymous1;

	try
	{
		anonymous1.increaseGrade();
		std::cout << anonymous1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << anonymous1 << std::endl;
	}

	std::cout << std::endl;
	Bureaucrat	anonymous2("anonymous2", 10);
	try
	{
		anonymous2.increaseGrade();
		std::cout << anonymous2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << anonymous2 << std::endl;
	}


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "=============== GradeTooLowException ===============" << std::endl;
	Bureaucrat	anonymous3("anonymous3", 150);

	try
	{
		anonymous3.decreaseGrade();
		std::cout << anonymous3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << anonymous3 << std::endl;
	}

	std::cout << std::endl;
	Bureaucrat	anonymous4("anonymous4", 149);
	try
	{
		anonymous4.decreaseGrade();
		std::cout << anonymous4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << anonymous4 << std::endl;
	}

	return (0);
}