/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:31:46 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/10 19:35:58 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery", shru_sign, shru_exec), _target("Unknown Target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) 
	: AForm("Shrubbery", shru_sign, shru_exec), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string formName, const std::string target) 
	: AForm(formName, shru_sign, shru_exec), _target(target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this != &form)
	{
		this->_target = form.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) 
	: AForm(form.getFormName(), shru_sign, shru_exec)
{
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

bool	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (executor.getGrade() <= this->getExecGrade() && this->getIsSigned())
		{
			std::string		filename = this->getTarget() += "_shrubbery";
			std::ofstream	printFile;
			printFile.open(filename);
			printFile << "          _-_         " << std::endl;
			printFile << "       /~~   ~~\\     " << std::endl;
			printFile << "    /~~         ~~\\  " << std::endl;
			printFile << "   {               }  " << std::endl;
			printFile << "    \\  _-     -_  /  " << std::endl;
			printFile << "      ~  \\ //  ~     " << std::endl;
			printFile << "    _- -  | | _- _   " << std::endl;
			printFile << "      _ - | |   -_   " << std::endl;
			printFile << "         // \\       " << std::endl;
			printFile.close();
			return (true);
		}
		else
			throw AForm::GradeTooLowException(4);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << executor << std::endl;
		std::cout << *this << std::endl;
	}
	return (false);
}
