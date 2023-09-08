/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:58:45 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/08 18:35:23 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <random>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

enum robotomyInfo
{
	robo_sign = 72,
	robo_exec = 45
};

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string _formName);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &form);
		~RobotomyRequestForm();
		// bool	getIsExecuted(void) const;
		void	execute(Bureaucrat const &executor) const;
	// private:
	// 	bool	isExecuted;
};

// std::ostream& operator<<(std::ostream& outputStream, const AForm& form);

#endif