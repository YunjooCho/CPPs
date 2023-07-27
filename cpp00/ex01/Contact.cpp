/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:51:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/27 18:24:09 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"

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

int	Contact::checkPhoneNumber(std::string phoneNumber)
{
	for (int i = 0; i < (int)phoneNumber.length(); i++)
	{
		if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
			return (0);
	}
	return (1);
}

void	Contact::createNewContact(Contact *contact, int idx)
{
	size_t		find_idx;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << idx + 1 << ")) 이름을 입력하세요 : " << std::endl;
	std::getline(std::cin, firstName);
	meetEof();
	firstName = strtrim(firstName);
	while (firstName.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cout << idx + 1 << ")) 이름을 입력하세요 : " << std::endl;
		std::getline(std::cin, firstName);
		firstName = strtrim(firstName);
	}
	find_idx = firstName.find_first_of("\t");
	while (find_idx != std::string::npos)
	{
		firstName[find_idx] = ' ';
		find_idx = firstName.find_first_of("\t", find_idx + 1);
	}
	
	std::cout << idx + 1 << ")) 성을 입력하세요 : " << std::endl;
	std::getline(std::cin, lastName);
	meetEof();
	lastName = strtrim(lastName);
	while (lastName.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cout << idx + 1 << ")) 성을 입력하세요 : " << std::endl;
		std::getline(std::cin, lastName);
		lastName = strtrim(lastName);
	}
	find_idx = lastName.find_first_of("\t");
	while (find_idx != std::string::npos)
	{
		lastName[find_idx] = ' ';
		find_idx = lastName.find_first_of("\t", find_idx + 1);
	}
	std::cout << idx + 1 << ")) 별명을 입력하세요 : " << std::endl;
	std::getline(std::cin, nickname);
	meetEof();
	nickname = strtrim(nickname);
	while (nickname.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cout << idx + 1 << ")) 별명을 입력하세요 : " << std::endl;
		std::getline(std::cin, nickname);
		nickname = strtrim(nickname);
	}
	find_idx = nickname.find_first_of("\t");
	while (find_idx != std::string::npos)
	{
		nickname[find_idx] = ' ';
		find_idx = nickname.find_first_of("\t", find_idx + 1);
	}
	std::cout << idx + 1 << ")) 전화번호를 입력하세요 : ('-' 제외)" << std::endl;
	std::getline(std::cin, phoneNumber);
	meetEof();
	phoneNumber = strtrim(phoneNumber);
	while (phoneNumber.length() <= 0 || !checkPhoneNumber(phoneNumber))
	{	
		if (phoneNumber.length() <= 0)
			std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		if (!checkPhoneNumber(phoneNumber))
			std::cout << "** 전화번호가 유효하지 않습니다. **" << std::endl;
		meetEof();
		std::cout << idx + 1 << ")) 전화번호를 입력하세요 : ('-' 제외)" << std::endl;
		std::getline(std::cin, phoneNumber);
		phoneNumber = strtrim(phoneNumber);
	}
	find_idx = nickname.find_first_of("\t");
	while (find_idx != std::string::npos)
	{
		nickname[find_idx] = ' ';
		find_idx = nickname.find_first_of("\t", find_idx + 1);
	}
	std::cout << idx + 1 << ")) 비밀을 입력하세요 : " << std::endl;
	std::getline(std::cin, darkestSecret);
	meetEof();
	darkestSecret = strtrim(darkestSecret);
	while (darkestSecret.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cin.clear();
		std::cout << idx + 1 << ")) 비밀을 입력하세요 : " << std::endl;
		std::getline(std::cin, darkestSecret);
		darkestSecret = strtrim(darkestSecret);
	}
	find_idx = darkestSecret.find_first_of("\t");
	while (find_idx != std::string::npos)
	{
		darkestSecret[find_idx] = ' ';
		find_idx = darkestSecret.find_first_of("\t", find_idx + 1);
	}
	std::cout << "** 입력이 완료 되었습니다. **" << std::endl;
	contact->setVariables(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

void	Contact::chagePrintString(std::string str)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		int	len = 10 - str.length() + 1;
		std::cout << std::setw(len);
		for (size_t i = 0; i < str.length(); i++)
			std::cout << str[i];
	}
}