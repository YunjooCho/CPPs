/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:03:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/02 22:18:13 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("anonymous"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string _name, int _grade) : name(_name)
{
	if (_grade < 0)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = _grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
	{
		this->grade = bureaucrat.getGrade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::increaseGrade(const unsigned int amount)
{
	this->grade -= amount;
	if (this->grade < 0)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(const unsigned int amount)
{
	this->grade += amount;
	if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too High!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too Low!";
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat)
{
	outputStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outputStream);
}

