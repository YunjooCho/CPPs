/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:52:30 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/10 01:19:23 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential", president_sign, president_exec), _target("Unknown Target")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) 
	: AForm("Presidential", president_sign, president_exec), _target(target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
	{
		this->_target = form.getTarget();
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
	return (this->_target);
}

bool	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() <= this->getExecGrade() && this->getIsSigned())
		{
			std::cout << "[INFO] " << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		}
		else
			throw AForm::GradeTooLowException(4);
		return (true);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << executor << std::endl;
		std::cout << *this << std::endl;
	}
	return (false);
}
