/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:58:45 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/29 19:20:17 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

enum shrubberyInfo
{
	shru_sign = 145,
	shru_exec = 137
};

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &form);
		~ShrubberyCreationForm();
		std::string	getTarget(void) const;
		bool		execute(Bureaucrat const &executor) const;
	private:
		std::string	_target;
};

#endif