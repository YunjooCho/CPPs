/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 17:26:04 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/03 21:59:24 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	_leaks()
{
	system("leaks a.out");
}

int	main(void)
{
	Bureaucrat	captain("Steve", 1);
	Bureaucrat	shield("Phill", 70);
	Form		form1("TopSecret", 1, 1);
	Form		form2("Contacts", 100, 100);
	Form		form3("TopSecret2", 1, 1);
	Form		form4("Contacts2", 100, 100);

	std::cout << "=============== Captain America  - TopSecret ===============" << std::endl;
	// try
	// {
	// 	form1.beSigned(captain);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	std::cout << captain << std::endl;
	// 	std::cout << form1 << std::endl;
	// }
	try
	{
		captain.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << captain << std::endl;
		std::cout << form1 << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=============== Captain America - Contacts ===============" << std::endl;
	// try
	// {
	// 	form2.beSigned(captain);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	std::cout << captain << std::endl;
	// 	std::cout << form2 << std::endl;
	// }
	try
	{
		captain.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << captain << std::endl;
		std::cout << form2 << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=============== S.H.E.I.L.D Agent - TopSecret ===============" << std::endl;
	// try
	// {
	// 	form3.beSigned(shield);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	std::cout << shield << std::endl;
	// 	std::cout << form3 << std::endl;
	// }
	try
	{
		shield.signForm(form3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << shield << std::endl;
		std::cout << form3 << std::endl;
	}
	std::cout << std::endl;
	std::cout << "=============== S.H.E.I.L.D Agent - Contacts ===============" << std::endl;
	// try
	// {
	// 	form4.beSigned(shield);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cout << e.what() << std::endl;
	// 	std::cout << shield << std::endl;
	// 	std::cout << form4 << std::endl;
	// }
	try
	{
		shield.signForm(form4);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << shield << std::endl;
		std::cout << form4 << std::endl;
	}
	return (0);
}