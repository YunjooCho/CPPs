/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:42:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/30 17:08:24 by yunjcho          ###   ########.fr       */
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
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increaseGrade(void);
		void		decreaseGrade(void);
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
		const std::string	_name;
		int					_grade;
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat& operator=(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat);

#endif