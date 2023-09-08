/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:31:46 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/08 18:22:58 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Unknown", shru_sign, shru_exec) //, isExecuted(false)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string _formName) 
	: AForm(_formName, shru_sign, shru_exec) //, isExecuted(false)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	if (this != &form)
	{
		// this->isSigned = form.getIsSigned(); //setter?
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) 
	: AForm(form.getFormName(), shru_sign, shru_exec) //, isExecuted(false) 
{
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {};

// bool	ShrubberyCreationForm::getIsExecuted(void) const
// {
// 	return (this->isExecuted);
// }

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		// Bureaucrat tmp(executor.getName(), executor.getGrade());
		// AForm::beSigned(tmp);
		if (executor.getGrade() <= this->getExecGrade())
		{
			std::string		filename = executor.getName() += "_shrubbery";
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
}

// std::ostream& operator<<(std::ostream& outputStream, const ShrubberyCreationForm& form)
// {
// 	outputStream << "[ShrubberyCreationForm::INFO] Formname : " << form.getFormName() \
// 					<< ", IsSigned : " << form.getIsSigned() \
// 					<< ", IsExecuted : " << form.getIsExecuted() \
// 					<< ", SignGrade : " << form.getSignGrade() \
// 					<< ", ExecGrade : " << form.getExecGrade();
// 	return (outputStream);
// }