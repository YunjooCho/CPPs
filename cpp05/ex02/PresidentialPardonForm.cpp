/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:52:30 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/10 14:29:11 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential", president_sign, president_exec), _target("Unknown Target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
	: AForm("Presidential", president_sign, president_exec), _target(target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
	{
		_target = form._target;
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) 
	: AForm(form.getFormName(), president_sign, president_exec)
{
	*this = form;
}

PresidentialPardonForm::~PresidentialPardonForm() {};

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() <= this->getExecGrade() && this->getIsSigned())
		{
			std::cout << "[INFO] " << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
			return (true);
		}
		else if (!this->getIsSigned())
			throw AForm::GradeTooLowException(4);
		else if (executor.getGrade() > this->getExecGrade())
			throw AForm::GradeTooLowException(5);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << executor << std::endl;
		std::cout << *this << std::endl;
	}
	return (false);
}
