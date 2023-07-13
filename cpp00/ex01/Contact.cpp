/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:51:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/13 15:02:43 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::setVariables(std::string _firstName, \
	std::string _lastName, std::string _nickname, \
	std::string _phoneNumber, std::string _darkestSecret)
{
	this->firstName = _firstName;
	this->lastName = _lastName;
	this->nickname = _nickname;
	this->phoneNumber = _phoneNumber;
	this->darkestSecret = _darkestSecret;
}

std::string	Contact::getFirstName(void)
{
	return this->firstName;
}

std::string	Contact::getLastName(void)
{
	return this->lastName;
}

std::string	Contact::getNickname(void)
{
	return this->nickname;
}

std::string	Contact::getPhoneNumber(void)
{
	return this->phoneNumber;
}

std::string	Contact::getDarkestSecret(void)
{
	return this->darkestSecret;
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
		int	len = 10 - str.length() + 1;
		std::cout << std::setw(len);
		for (size_t i = 0; i < str.length(); i++)
			std::cout << str[i];
	}
}