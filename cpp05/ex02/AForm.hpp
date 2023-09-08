/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:30:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/08 16:24:36 by yunjcho          ###   ########seoul.kr  */
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
		AForm(const std::string _formName, const int _signGrade, const int _execGrade);
		AForm(const AForm &form);
		AForm& operator=(const AForm &form);
		~AForm();
		std::string		getFormName(void) const;
		bool			getIsSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;
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
		const int			execGrade;
};

std::ostream& operator<<(std::ostream& outputStream, const AForm& form);

#endif