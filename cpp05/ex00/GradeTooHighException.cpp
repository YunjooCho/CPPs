/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:38:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/01 16:41:15 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeTooHighException.hpp"

GradeTooHighException::GradeTooHighException(const std::string &err)
{
	
}

std::string	GradeTooHighException::getMessage(void) const
{
	return (this->errorMsg);
}

std::ostream& operator<<(std::ostream& outputStream, const GradeTooHighException& bureaucrat)
{
	outputStream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outputStream);
}