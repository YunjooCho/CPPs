/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:27:36 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 19:26:43 by yunjcho          ###   ########.fr       */
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
	artist1.executeForm(art1);
	
	std::cout << std::endl;
	artist2.executeForm(art1);
	
	std::cout << std::endl;
	artist1.executeForm(art2);
	
	std::cout << std::endl;
	artist2.executeForm(art2);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "====================== RobotomyRequestForm Testcase ======================" << std::endl;
	Bureaucrat human1("John", 45);
	Bureaucrat human2("Jane", 72);

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
	human1.executeForm(rrf1);
	
	std::cout << std::endl;
	human2.executeForm(rrf1);

	std::cout << std::endl;
	RobotomyRequestForm rrf2("Leg");

	std::cout << std::endl;
	human1.executeForm(rrf2);
	
	std::cout << std::endl;
	human2.executeForm(rrf2);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "====================== PresidentialPardonForm Testcase ======================" << std::endl;
	Bureaucrat jailer1("Tom", 3);
	Bureaucrat jailer2("Tim", 25);
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
	jailer1.executeForm(ppf1);

	std::cout << std::endl;
	jailer2.executeForm(ppf1);


	std::cout << std::endl;
	std::cout << std::endl;
	PresidentialPardonForm ppf2("Prisoner2");

	jailer1.executeForm(ppf2);

	std::cout << std::endl;
	jailer2.executeForm(ppf2);

	return (0);
}