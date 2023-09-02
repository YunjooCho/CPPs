/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:55:13 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/02 22:16:47 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : formName("Unknown"), isSigned(false), signGrade(150), executeGrade(150) {}

Form::Form(const std::string _formName, const int _signGrade, const int _executeGrade) 
	: formName(_formName), signGrade(_signGrade), executeGrade(_executeGrade) {}

Form& Form::operator=(const Form &form)
{
	if (this != &form)
	{
		this->isSigned = form.getIsSigned();
	}
	return (*this);
}

Form::Form(const Form &form)
{
	*this = form;
}

Form::~Form() {};

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

}