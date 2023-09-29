/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:55:13 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 18:45:22 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _formName("Unknown"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string &formName, const int &signGrade, const int &execGrade)
	: _formName(formName), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) 
{
	if (_signGrade < 1)
		throw Form::GradeTooHighException(1);
	else if (_signGrade > 150)
		throw Form::GradeTooLowException(1);
	else if (_execGrade < 1)
		throw Form::GradeTooHighException(2);
	else if (_execGrade > 150)
		throw Form::GradeTooLowException(2);
}

Form& Form::operator=(const Form &form)
{
	if (this != &form)
	{
		_isSigned = form._isSigned;
	}
	return (*this);
}

Form::Form(const Form &form) 
	: _formName(form._formName), _signGrade(form._signGrade), \
	  _execGrade(form._execGrade) 
{
	*this = form;
}

Form::~Form() {};

Form::GradeTooHighException::GradeTooHighException(const int &errCode)
	: _errCode(errCode) {}

const char *Form::GradeTooHighException::what(void) const throw()
{
	if (_errCode == 1)
		return "[Form::Exception] Form's SignGrade is too High!";
	else if (_errCode == 2)
		return "[Form::Exception] Form's ExecuteGrade is too High!";
	return "[Form::Exception] Grade is too High!";
}

Form::GradeTooLowException::GradeTooLowException(const int &errCode)
	: _errCode(errCode) {}

const char *Form::GradeTooLowException::what(void) const throw()
{
	if (_errCode == 1)
		return "[Form::Exception] Form's SignGrade is too Low!";
	else if (_errCode == 2)
		return "[Form::Exception] Form's ExecuteGrade is too Low!";
	else if (_errCode == 3)
		return "Bureaucrat's Grade lower than Form's SignGrade!";
	return "[Form::Exception] Grade is too Low!";
}

std::string	Form::getFormName(void) const
{
	return (_formName);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (_execGrade);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signGrade)
		_isSigned = true;
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
