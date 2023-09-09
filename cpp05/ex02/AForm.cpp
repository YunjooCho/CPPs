/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:55:13 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/09 22:14:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : formName("Unknown"), isSigned(false), signGrade(150), execGrade(150) {}

AForm::AForm(const std::string _formName, const int _signGrade, const int _execGrade) 
	: formName(_formName), isSigned(false), signGrade(_signGrade), execGrade(_execGrade) 
{
	if (this->signGrade < 0)
		throw AForm::GradeTooHighException(1);
	else if ((this->signGrade > 150))
		throw AForm::GradeTooLowException(1);
	else if (this->execGrade < 0)
		throw AForm::GradeTooHighException(2);
	else if (this->execGrade > 150)
		throw AForm::GradeTooLowException(2);
}

AForm& AForm::operator=(const AForm &form)
{
	if (this != &form)
	{
		this->isSigned = form.getIsSigned();
	}
	return (*this);
}

AForm::AForm(const AForm &form) 
	: formName(form.getFormName()), signGrade(form.getSignGrade()), \
	  execGrade(form.getExecGrade()) 
{
	*this = form;
}

AForm::~AForm() {};

AForm::GradeTooHighException::GradeTooHighException(const int _errCode)
	: errCode(_errCode) {}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	if (this->errCode == 1)
		return "[Exception] Form's SignGrade is too High!";
	else if (this->errCode == 2)
		return "[Exception] Form's ExecuteGrade is too High!";
	return "[Exception] Grade is too High!";
}

AForm::GradeTooLowException::GradeTooLowException(const int _errCode)
	: errCode(_errCode) {}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	if (this->errCode == 1)
		return "[Exception] Form's SignGrade is too Low!";
	else if (this->errCode == 2)
		return "[Exception] Form's ExecuteGrade is too Low!";
	else if (this->errCode == 3)
		return "Bureaucrat's Grade lower than Form's SignGrade!";
	else if (this->errCode == 4)
		return "Bureaucrat's Grade lower than Form's ExecGrade or No signed Form!";
	return "[Exception] Grade is too Low!";
}

std::string	AForm::getFormName(void) const
{
	return (this->formName);
}

bool	AForm::getIsSigned(void) const
{
	return (this->isSigned);
}

int	AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->execGrade);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signGrade)
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException(3);
}

std::ostream& operator<<(std::ostream& outputStream, const AForm& form)
{
	outputStream << "[Form::INFO] Formname : " << form.getFormName() \
					<< ", IsSigned : " << form.getIsSigned() \
					<< ", SignGrade : " << form.getSignGrade() \
					<< ", ExecGrade : " << form.getExecGrade();
	return (outputStream);
}
