/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:55:13 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/04 19:01:40 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : formName("Unknown"), isSigned(false), signGrade(150), execGrade(150) {}

Form::Form(const std::string _formName, const int _signGrade, const int _execGrade) 
	: formName(_formName), isSigned(false), signGrade(_signGrade), execGrade(_execGrade) 
{
	if (this->signGrade < 0)
		throw Form::GradeTooHighException(1);
	else if ((this->signGrade > 150))
		throw Form::GradeTooLowException(1);
	else if (this->execGrade < 0)
		throw Form::GradeTooHighException(2);
	else if (this->execGrade > 150)
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
	  execGrade(form.getExecGrade()) 
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
		return "[Exception] Form's Execrade is too High!";
	return "[Exception] Grade is too High!";
}

Form::GradeTooLowException::GradeTooLowException(const int _errCode)
	: errCode(_errCode) {}

const char *Form::GradeTooLowException::what(void) const throw()
{
	if (this->errCode == 1)
		return "[Exception] Form's SignGrade is too Low!";
	else if (this->errCode == 2)
		return "[Exception] Form's ExecGrade is too Low!";
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

int	Form::getExecGrade(void) const
{
	return (this->execGrade);
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
					<< ", ExecGrade : " << form.getExecGrade();
	return (outputStream);
}
