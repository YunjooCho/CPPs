/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:27:36 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/09 19:48:43 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "====================== ShrubberyCreationForm Testcase ======================" << std::endl;
	Bureaucrat artist1("Artist", 137);
	Bureaucrat artist2("Aspiring Artist", 150);
	ShrubberyCreationForm art1("Tree1");

	art1.execute(artist1);
	art1.execute(artist2);

	std::cout << std::endl;
	std::cout << "====================== RobotomyRequestForm Testcase ======================" << std::endl;
	Bureaucrat human1("John", 72);
	Bureaucrat human2("Jane", 45);

	RobotomyRequestForm rrf("R.r.f.");
	rrf.execute(human1);
	rrf.execute(human2);

	// RobotomyRequestForm rrf2("R.r.f.2"); // 위와 같은 난수가 생성되어 결과값이 동일
	// rrf2.execute(human1);
	// rrf2.execute(human2);
	return (0);
}