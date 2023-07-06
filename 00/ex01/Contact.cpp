/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:51:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/06 19:46:20 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.h"

void	Contact::setVariables(int idx, std::string _firstName, \
	std::string _lastName, std::string _nickname, \
	std::string _phoneNumber, std::string _darkestSecret)
{
	id = idx;
	firstName = _firstName;
	lastName = _lastName;
	nickname = _nickname;
	phoneNumber = _phoneNumber;
	darkestSecret = _darkestSecret;
}

std::string	Contact::getFirstName(void)
{
	return firstName;
}

std::string	Contact::getLasttName(void)
{
	return lastName;
}

std::string	Contact::getNickname(void)
{
	return nickname;
}