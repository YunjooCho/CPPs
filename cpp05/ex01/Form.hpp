/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:30:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/03 21:32:51 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const std::string _formName, const int _signGrade, const int _executeGrade);
		Form(const Form &form);
		Form& operator=(const Form &form);
		~Form();
		std::string	getFormName(void) const;
		bool		getIsSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecuteGrade(void) const;
		void		beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception 
		{
			public:
				GradeTooHighException(const int _errCode);
				const char *what(void) const throw();
			private:
				const int	errCode;
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				GradeTooLowException(const int _errCode);
				const char *what(void) const throw();
			private:
				const int	errCode;
		};
	private:
		const std::string	formName;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;
};

std::ostream& operator<<(std::ostream& outputStream, const Form& form);

#endif