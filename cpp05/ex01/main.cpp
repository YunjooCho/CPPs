/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:26:04 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 18:31:31 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	captain("Steve", 1);
	Bureaucrat	shield("Phill", 70);
	Form		form1("TopSecret", 1, 1);
	Form		form2("Contacts", 100, 100);
	Form		form3("TopSecret2", 1, 1);
	Form		form4("Contacts2", 100, 100);
	Form		form5("Contacts3", 100, 100);

	std::cout << "=============== Captain America  - TopSecret ===============" << std::endl;
	try
	{
		captain.signForm(form1);
		std::cout << captain << std::endl;
		std::cout << form1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << captain << std::endl;
		std::cout << form1 << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=============== Captain America - Contacts ===============" << std::endl;
	try
	{
		captain.signForm(form2);
		std::cout << captain << std::endl;
		std::cout << form2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << captain << std::endl;
		std::cout << form2 << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=============== S.H.E.I.L.D Agent - TopSecret ===============" << std::endl;
	try
	{
		shield.signForm(form3);
		std::cout << shield << std::endl;
		std::cout << form3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << shield << std::endl;
		std::cout << form3 << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=============== S.H.E.I.L.D Agent - Contacts ===============" << std::endl;
	try
	{
		shield.signForm(form4);
		std::cout << shield << std::endl;
		std::cout << form4 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << shield << std::endl;
		std::cout << form4 << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=============== S.H.E.I.L.D Agent Decreasing Grade - Contacts ===============" << std::endl;
	for (int i = 0; i < 50; i++)
	{
		shield.decreaseGrade();
	}
	try
	{
		shield.signForm(form5);
		std::cout << shield << std::endl;
		std::cout << form5 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << shield << std::endl;
		std::cout << form5 << std::endl;
	}
	return (0);
}