/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:30:08 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 19:39:02 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum Code
{
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENTIAL,
};

typedef struct s_codes
{
	std::string	key;
	int			val;
}	t_codes;

Intern::Intern() {}

Intern& Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern() {}

std::string	Intern::stringToUppercase(std::string formName)
{
	char	copyName[1024];

	std::size_t len = formName.copy(copyName, formName.length(), 0);
	copyName[len] = '\0';
	for (size_t i = 0; i < formName.length(); i++)
	{
		copyName[i] = std::toupper(copyName[i]);
	}
	return (copyName);
} 

AForm *Intern::makeForm(std::string formName, std::string target)
{
	int	result = -1;
	t_codes codes[4] = {
		{"SHRUBBERY", SHRUBBERY}, {"ROBOTOMY", ROBOTOMY}, {"PRESIDENTIAL", PRESIDENTIAL}
	};

	std::string copyName = stringToUppercase(formName);
	for (int i = 0; i < 3; i++)
	{
		if (copyName.find(codes[i].key) != std::string::npos)
		{
			result = codes[i].val;
			std::cout << "Intern creates " << formName << std::endl;
			break ;
		}
	}
	switch (result)
	{
		case SHRUBBERY:
			return (new ShrubberyCreationForm(formName, target));
		case ROBOTOMY:
			return (new RobotomyRequestForm(formName, target));
		case PRESIDENTIAL:
			return (new PresidentialPardonForm(formName, target));
		case -1:
			std::cout << "[Intern::INFO makeForm() FAILURE] Explicit error -  Formname doesn’t exist" << std::endl;
	}
	return (NULL);
}