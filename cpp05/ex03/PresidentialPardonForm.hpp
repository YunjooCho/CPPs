/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:58:45 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/10 17:49:48 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

enum presidentInfo
{
	president_sign = 25,
	president_exec = 5
};

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const std::string formName, const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &form);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &form);
		~PresidentialPardonForm();
		std::string	getTarget(void) const;
		bool		execute(Bureaucrat const &executor) const;
	private:
		std::string	_target;
};

#endif