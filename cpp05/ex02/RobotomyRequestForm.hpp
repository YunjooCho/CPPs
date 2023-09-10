/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:58:45 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/10 17:46:40 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
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
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &form);
		~RobotomyRequestForm();
		std::string	getTarget(void) const;
		bool		execute(Bureaucrat const &executor) const;
	private:
		std::string	_target;
};

#endif