/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:03:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/09 22:27:19 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "[SUCCESS] " << this->name << " signed " << form.getFormName() << std::endl;
	}
	catch(const std::exception& e) 
	{
		std::cout << "[FAILURE] " << this->name << " couldn’t sign " << form.getFormName() \
			<< " because ";
		throw AForm::GradeTooLowException(3);
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	Bureaucrat tmp(*this);
	if (form.execute(tmp) == true)
	{
		std::cout << this->name << " executed " << form.getFormName() << std::endl;
	}
	else
		throw std::runtime_error("explicit error");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "[Exception] Bureaucrat's Grade is too High!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "[Exception] Bureaucrat's Grade is too Low!";
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat)
{
	outputStream <<  "[Bureaucrat::INFO] " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outputStream);
}