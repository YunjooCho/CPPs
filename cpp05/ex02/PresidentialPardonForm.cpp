/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:52:30 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/09 19:57:06 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Unknown", president_sign, president_exec) //, isExecuted(false)
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string _formName) 
	: AForm(_formName, president_sign, president_exec) //, isExecuted(false)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
	{
		// this->isSigned = form.getIsSigned(); //setter?
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) 
	: AForm(form.getFormName(), president_sign, president_exec) //, isExecuted(false) 
{
	*this = form;
}

PresidentialPardonForm::~PresidentialPardonForm() {};

// bool	RobotomyRequestForm::getIsExecuted(void) const
// {
// 	return (this->isExecuted);
// }

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() <= this->getExecGrade())
		{
			
		}
		else
			throw AForm::GradeTooLowException(4);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
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