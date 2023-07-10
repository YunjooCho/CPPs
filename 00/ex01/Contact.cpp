/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:51:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 18:35:12 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	Contact::setVariables(std::string _firstName, \
	std::string _lastName, std::string _nickname, \
	std::string _phoneNumber, std::string _darkestSecret)
{
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

std::string	Contact::getLastName(void)
{
	return lastName;
}

std::string	Contact::getNickname(void)
{
	return nickname;
}

std::string	Contact::getPhoneNumber(void)
{
	return phoneNumber;
}

std::string	Contact::getDarkestSecret(void)
{
	return darkestSecret;
}

void	Contact::chagePrintString(std::string str)
{
	if (str.length() > 10)
	{
		for (size_t i = 0; i < 9; i++)
		{
			std::cout << str[i];
		}
		std::cout << ".";
	}
	else
	{
		for (size_t i = 0; i < str.length(); i++)
			std::cout << str[i];
	}
}