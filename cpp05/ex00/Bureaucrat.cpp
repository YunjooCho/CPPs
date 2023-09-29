/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:03:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 18:28:22 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("anonymous"), _grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		_grade = bureaucrat._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increaseGrade(void)
{
	--(_grade);
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(void)
{
	++(_grade);
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "[Bureaucrat::Exception] Bureaucrat's Grade is too High!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "[Bureaucrat::Exception] Bureaucrat's Grade is too Low!";
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat)
{
	outputStream << "[Bureaucrat::INFO] "<< bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outputStream);
}

