/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:27:36 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/10 15:17:36 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "====================== ShrubberyCreationForm Testcase ======================" << std::endl;
	Bureaucrat artist1("Artist", 137);
	Bureaucrat artist2("Aspiring Artist", 150);
	ShrubberyCreationForm art1("Home");
	ShrubberyCreationForm art2("Park");

	try
	{
		artist1.signForm(art1);
		std::cout << artist1 << std::endl;
		std::cout << art1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << artist1 << std::endl;
		std::cout << art1 << std::endl;
	}
	std::cout << std::endl;
	try
	{
		artist1.executeForm(art1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << artist1 << std::endl;
		std::cout << art1 << std::endl;
	}
	std::cout << std::endl;
	try
	{
		artist2.executeForm(art1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	try
	{
		artist1.executeForm(art2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		artist2.executeForm(art2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "====================== RobotomyRequestForm Testcase ======================" << std::endl;
	Bureaucrat human1("John", 72);
	Bureaucrat human2("Jane", 45);

	RobotomyRequestForm rrf1("Arm");
	try
	{
		human1.signForm(rrf1);
		std::cout << human1 << std::endl;
		std::cout << rrf1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << human1 << std::endl;
		std::cout << rrf1 << std::endl;
	}
	std::cout << std::endl;
	try
	{
		human1.executeForm(rrf1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		human2.executeForm(rrf1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	RobotomyRequestForm rrf2("Leg"); // TODO - 위와 같은 난수가 생성되어 결과값이 동일한 문제발생
	try
	{
		human1.executeForm(rrf2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		human2.executeForm(rrf2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "====================== PresidentialPardonForm Testcase ======================" << std::endl;
	Bureaucrat jailer1("Tom", 25);
	Bureaucrat jailer2("Tim", 3);

	PresidentialPardonForm ppf1("Prisoner1");
	try
	{
		jailer1.signForm(ppf1);
		std::cout << jailer1 << std::endl;
		std::cout << ppf1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << jailer1 << std::endl;
		std::cout << ppf1 << std::endl;
	}
	std::cout << std::endl;
	try
	{
		jailer1.executeForm(ppf1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		jailer2.executeForm(ppf1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	PresidentialPardonForm ppf2("Prisoner2");
		try
	{
		jailer1.executeForm(ppf2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		jailer2.executeForm(ppf2);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}