/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:03:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/01 17:38:52 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("anonymous"), grade(1) {}

Bureaucrat::Bureaucrat(const int grade) : name("anonymous"), grade(grade) {}

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

int		Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::increaseGrade(const int amount)
{
	if ((this->grade - amount) < 0)
		throw GradeTooHighException();
}

void	Bureaucrat::decreaseGrade(const int amount)
{
	if ((this->grade + amount) > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat)
{
	outputStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outputStream);
}

