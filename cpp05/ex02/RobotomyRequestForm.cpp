/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:31:46 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/08 18:56:47 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Unknown", robo_sign, robo_exec) //, isExecuted(false)
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string _formName) 
	: AForm(_formName, robo_sign, robo_exec) //, isExecuted(false)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
	{
		// this->isSigned = form.getIsSigned(); //setter?
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) 
	: AForm(form.getFormName(), robo_sign, robo_exec) //, isExecuted(false) 
{
	*this = form;
}

RobotomyRequestForm::~RobotomyRequestForm() {};

// bool	RobotomyRequestForm::getIsExecuted(void) const
// {
// 	return (this->isExecuted);
// }

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	// Bureaucrat tmp(executor.getName(), executor.getGrade());
	// AForm::beSigned(tmp);
	try
	{
		if (executor.getGrade() <= this->getExecGrade())
		{
			std::cout << "Whirr~" << std::endl;
			//TODO - 랜덤 숫자 생성하기(0, 1)
			//0이면 실패, 1이면 성공
		}
		else
			throw AForm::GradeTooLowException(4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// std::ostream& operator<<(std::ostream& outputStream, const ShrubberyCreationForm& form)
// {
// 	outputStream << "[ShrubberyCreationForm::INFO] Formname : " << form.getFormName() \
// 					<< ", IsSigned : " << form.getIsSigned() \
// 					<< ", IsExecuted : " << form.getIsExecuted() \
// 					<< ", SignGrade : " << form.getSignGrade() \
// 					<< ", ExecGrade : " << form.getExecGrade();
// 	return (outputStream);
// }