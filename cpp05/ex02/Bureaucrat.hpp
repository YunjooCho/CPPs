/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:42:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/08 16:29:58 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string _name, int _grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat& operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increaseGrade(const unsigned int amount);
		void		decreaseGrade(const unsigned int amount);
		void		signForm(AForm &form);
		void		executeForm(AForm const &form);
		class GradeTooHighException : public std::exception 
		{
			public:
				const char *what(void) const throw();
				
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				const char *what(void) const throw();
		};
	private:
		const std::string	name;
		int					grade;
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat);

#endif