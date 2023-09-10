/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:21:53 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/10 18:02:06 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &form);
		Intern& operator=(const Intern &form);
		~Intern();
		std::string	stringToUppercase(std::string formName);
		AForm 		*makeForm(std::string formName, std::string target);
};

#endif