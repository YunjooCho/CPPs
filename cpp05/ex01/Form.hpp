/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:30:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 18:38:18 by yunjcho          ###   ########.fr       */
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
		Form(const std::string &formName, const int &signGrade, const int &execGrade);
		Form(const Form &form);
		Form& operator=(const Form &form);
		~Form();
		std::string	getFormName(void) const;
		bool		getIsSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		void		beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException : public std::exception 
		{
			public:
				GradeTooHighException(const int &errCode);
				const char *what(void) const throw();
			private:
				const int	_errCode;
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				GradeTooLowException(const int &errCode);
				const char *what(void) const throw();
			private:
				const int	_errCode;
		};
	private:
		const std::string	_formName;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
};

std::ostream& operator<<(std::ostream& outputStream, const Form& form);

#endif