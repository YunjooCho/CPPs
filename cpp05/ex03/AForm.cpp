/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:55:13 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/10 14:25:25 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _formName("Unknown"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string &formName, const int &signGrade, const int &execGrade)
	: _formName(formName), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) 
{
	if (_signGrade < 1)
		throw AForm::GradeTooHighException(1);
	else if (_signGrade > 150)
		throw AForm::GradeTooLowException(1);
	else if (_execGrade < 1)
		throw AForm::GradeTooHighException(2);
	else if (_execGrade > 150)
		throw AForm::GradeTooLowException(2);
}

AForm& AForm::operator=(const AForm &form)
{
	if (this != &form)
	{
		_isSigned = form._isSigned;
	}
	return (*this);
}

AForm::AForm(const AForm &form) 
	: _formName(form._formName), _signGrade(form._signGrade), \
	  _execGrade(form._execGrade) 
{
	*this = form;
}

AForm::~AForm() {};

AForm::GradeTooHighException::GradeTooHighException(const int &errCode)
	: _errCode(errCode) {}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	if (_errCode == 1)
		return "[Form::Exception] Form's SignGrade is too High!";
	else if (_errCode == 2)
		return "[Form::Exception] Form's ExecuteGrade is too High!";
	return "[Form::Exception] Grade is too High!";
}

AForm::GradeTooLowException::GradeTooLowException(const int &errCode)
	: _errCode(errCode) {}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	if (_errCode == 1)
		return "[Form::Exception] Form's SignGrade is too Low!";
	else if (_errCode == 2)
		return "[Form::Exception] Form's ExecuteGrade is too Low!";
	else if (_errCode == 3)
		return "Bureaucrat's Grade lower than Form's SignGrade!";
	else if (_errCode == 4)
		return "[Form::Exception execute() FAILURE] No signed Form!";
	else if (_errCode == 5)
		return "[Form::Exception execute() FAILURE] Bureaucrat's Grade lower than Form's ExecGrade!";
	return "[Form::Exception] Grade is too Low!";
}

std::string	AForm::getFormName(void) const
{
	return (_formName);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (_execGrade);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
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
