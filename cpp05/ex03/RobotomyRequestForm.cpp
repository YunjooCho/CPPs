/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:31:46 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/10 19:35:08 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy", robo_sign, robo_exec), _target("Unknown Target")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) 
	: AForm("Robotomy", robo_sign, robo_exec), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string formName, const std::string target) 
	: AForm(formName, robo_sign, robo_exec), _target(target)
{}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
	{
		this->_target = form.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) 
	: AForm(form.getFormName(), robo_sign, robo_exec)
{
	*this = form;
}

RobotomyRequestForm::~RobotomyRequestForm() {};

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

bool	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() <= this->getExecGrade() && this->getIsSigned())
		{
			std::cout << "Whirr~" << std::endl;
			std::srand((unsigned int)time(NULL));
			int rand = std::rand() % 2;
			// std::cout << rand << std::endl;
			if (rand == 0)
			{
				std::cout << "[INFO - SUCCESS] " << this->_target << " has been robotomized!" << std::endl;
			}
			else
			{
				std::cout << "[INFO - FAILURE] " << this->_target << " failed robotomized..." << std::endl;
			}
			return (true);
		}
		else
			throw AForm::GradeTooLowException(4);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << executor << std::endl;
		std::cout << *this << std::endl;
	}
	return (false);
}