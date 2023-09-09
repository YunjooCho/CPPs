/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:27:36 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/09 20:53:00 by yunjcho          ###   ########.fr       */
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

	art1.execute(artist1);
	art1.execute(artist2);

	std::cout << std::endl;
	std::cout << "====================== RobotomyRequestForm Testcase ======================" << std::endl;
	Bureaucrat human1("John", 72);
	Bureaucrat human2("Jane", 45);

	RobotomyRequestForm rrf("Arm");
	rrf.execute(human1);
	rrf.execute(human2);

	// RobotomyRequestForm rrf2("R.r.f.2"); // TODO - 위와 같은 난수가 생성되어 결과값이 동일한 문제발생
	// rrf2.execute(human1);
	// rrf2.execute(human2);

	std::cout << std::endl;
	std::cout << "====================== PresidentialPardonForm Testcase ======================" << std::endl;
	Bureaucrat jailer1("Tom", 25);
	Bureaucrat jailer2("Tim", 3);

	PresidentialPardonForm ppf("Prisoner");
	ppf.execute(jailer1);
	ppf.execute(jailer2);
	return (0);
}