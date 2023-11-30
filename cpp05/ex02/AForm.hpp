/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:30:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/30 17:08:35 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const std::string &formName, const int &signGrade, const int &execGrade);
		virtual ~AForm();
		std::string		getFormName(void) const;
		bool			getIsSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		void			beSigned(Bureaucrat &bureaucrat);
		virtual bool	execute(Bureaucrat const &executor) const = 0;
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
		AForm(const AForm &form);
		AForm& operator=(const AForm &form);
};

std::ostream& operator<<(std::ostream& outputStream, const AForm& form);

#endif