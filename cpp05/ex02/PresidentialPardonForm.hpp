/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:58:45 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/09 20:01:50 by yunjcho          ###   ########.fr       */
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
		PresidentialPardonForm(const std::string _formName);
		PresidentialPardonForm(const PresidentialPardonForm &form);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &form);
		~PresidentialPardonForm();
		// bool	getIsExecuted(void) const;
		void	execute(Bureaucrat const &executor) const;
	// private:
	// 	bool	isExecuted;
};

// std::ostream& operator<<(std::ostream& outputStream, const AForm& form);

#endif