/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:27:36 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 19:42:12 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	president("president", 1);
	Intern		someRandomIntern;

	std::cout << "====================== ShrubberyCreationForm Testcase ======================" << std::endl;
	AForm*	sct;
	try
	{
		sct = someRandomIntern.makeForm("Shrubbery Creation", "White House");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		president.signForm(*sct);
		std::cout << president << std::endl;
		std::cout << *sct << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << president << std::endl;
		std::cout << *sct << std::endl;
	}
	std::cout << std::endl;
	president.executeForm(*sct);
	std::cout << president << std::endl;
	std::cout << *sct << std::endl;

	std::cout << std::endl;
	std::cout << "====================== RobotomyRequestForm Testcase ======================" << std::endl;
	AForm*	rrf;
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		president.signForm(*rrf);
		std::cout << president << std::endl;
		std::cout << *rrf << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << president << std::endl;
		std::cout << *rrf << std::endl;
	}
	std::cout << std::endl;
	try
	{
		president.executeForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << president << std::endl;
		std::cout << *rrf << std::endl;
	}

	std::cout << std::endl;
	std::cout << "====================== PresidentialPardonForm Testcase ======================" << std::endl;
	AForm*	pp;
	try
	{
		pp = someRandomIntern.makeForm("Presidential Pardon", "Prisoner");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		president.signForm(*pp);
		std::cout << president << std::endl;
		std::cout << *pp << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << president << std::endl;
		std::cout << *pp << std::endl;
	}
	std::cout << std::endl;
	try
	{
		president.executeForm(*pp);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << president << std::endl;
		std::cout << *pp << std::endl;
	}

	std::cout << std::endl;
	std::cout << "====================== makeForm() Exceptions Testcase ======================" << std::endl;
	AForm*	excep;

	excep = someRandomIntern.makeForm("Unknown", "Prisoner");

	delete sct;
	delete rrf;
	delete pp;
	// delete excep;
	return (0);
}