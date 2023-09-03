/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:55:13 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/03 21:59:59 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : formName("Unknown"), isSigned(false), signGrade(150), executeGrade(150) {}

Form::Form(const std::string _formName, const int _signGrade, const int _executeGrade) 
	: formName(_formName), isSigned(false), signGrade(_signGrade), executeGrade(_executeGrade) 
{
	if (this->signGrade < 0)
		throw Form::GradeTooHighException(1);
	else if ((this->signGrade > 150))
		throw Form::GradeTooLowException(1);
	else if (this->executeGrade < 0)
		throw Form::GradeTooHighException(2);
	else if (this->executeGrade > 150)
		throw Form::GradeTooLowException(2);
}

Form& Form::operator=(const Form &form)
{
	if (this != &form)
	{
		this->isSigned = form.getIsSigned();
	}
	return (*this);
}

Form::Form(const Form &form) 
	: formName(form.getFormName()), signGrade(form.getSignGrade()), \
	  executeGrade(form.getExecuteGrade()) 
{
	*this = form;
}

Form::~Form() {};

Form::GradeTooHighException::GradeTooHighException(const int _errCode)
	: errCode(_errCode) {}

const char *Form::GradeTooHighException::what(void) const throw()
{
	if (this->errCode == 1)
		return "[Exception] Form's SignGrade is too High!";
	else if (this->errCode == 2)
		return "[Exception] Form's ExecuteGrade is too High!";
	return "[Exception] Grade is too High!";
}

Form::GradeTooLowException::GradeTooLowException(const int _errCode)
	: errCode(_errCode) {}

const char *Form::GradeTooLowException::what(void) const throw()
{
	if (this->errCode == 1)
		return "[Exception] Form's SignGrade is too Low!";
	else if (this->errCode == 2)
		return "[Exception] Form's ExecuteGrade is too Low!";
	else if (this->errCode == 3)
		return "Bureaucrat's Grade lower than Form's SignGrade!";
	return "[Exception] Grade is too Low!";
}

std::string	Form::getFormName(void) const
{
	return (this->formName);
}

bool	Form::getIsSigned(void) const
{
	return (this->isSigned);
}

int	Form::getSignGrade(void) const
{
	return (this->signGrade);
}

int	Form::getExecuteGrade(void) const
{
	return (this->executeGrade);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw Form::GradeTooLowException(3);
}

std::ostream& operator<<(std::ostream& outputStream, const Form& form)
{
	outputStream << "[Form::INFO] Formname : " << form.getFormName() \
					<< ", IsSigned : " << form.getIsSigned() \
					<< ", SignGrade : " << form.getSignGrade() \
					<< ", ExecuteGrade : " << form.getExecuteGrade();
	return (outputStream);
}
