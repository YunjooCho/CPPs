/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:42:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/01 17:45:06 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(const int grade);
		Bureaucrat(const Bureaucrat &bureaucrat);
		Bureaucrat& operator=(const Bureaucrat &bureaucrat);
		~Bureaucrat();
		std::string		getName() const;
		int				getGrade() const;
		void			increaseGrade(const int amount);
		void			decreaseGrade(const int amount);
		class GradeTooHighException
		{
			public:
				GradeTooHighException();
		};
		class GradeTooLowException
		{
			public:
				GradeTooLowException();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat);

#endif