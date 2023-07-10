/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:51:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 17:48:50 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

int	checkPhoneNumber(std::string phoneNumber)
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
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << idx << ")) 이름을 입력하세요 : " << std::endl;
	std::getline(std::cin, firstName);
	meetEof();
	while (firstName.length() <= 0)
	{
		meetEof();
		std::cin.clear();
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		std::cout << idx << ")) 이름을 입력하세요 : " << std::endl;
		std::getline(std::cin, firstName);
	}
	std::cout << idx << ")) 성을 입력하세요 : " << std::endl;
	std::getline(std::cin, lastName);
	while (lastName.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cin.clear();
		std::cout << idx << ")) 성을 입력하세요 : " << std::endl;
		std::getline(std::cin, lastName);
	}
	std::cout << idx << ")) 별명을 입력하세요 : " << std::endl;
	std::getline(std::cin, nickname);
	while (nickname.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cin.clear();
		std::cout << idx << ")) 별명을 입력하세요 : " << std::endl;
		std::getline(std::cin, nickname);
	}
	std::cout << idx << ")) 전화번호를 입력하세요 : ('-' 제외)" << std::endl;
	std::getline(std::cin, phoneNumber);
	while (phoneNumber.length() <= 0 || checkPhoneNumber(phoneNumber) == 0)
	{	
		std::cin.clear();
		if (phoneNumber.length() <= 0)
			std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		if (!checkPhoneNumber(phoneNumber))
			std::cout << "** 전화번호가 유효하지 않습니다. **" << std::endl;
		else
			break;
		std::cout << idx << ")) 전화번호를 입력하세요 : ('-' 제외)" << std::endl;
		std::getline(std::cin, phoneNumber);
	}
	std::cout << idx << ")) 비밀을 입력하세요 : " << std::endl;
	std::getline(std::cin, darkestSecret);
	while (darkestSecret.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cin.clear();
		std::cout << idx << ")) 비밀을 입력하세요 : " << std::endl;
		std::getline(std::cin, darkestSecret);
	}
	std::cout << "** 입력이 완료 되었습니다. **" << std::endl;
	contact->setVariables(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

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
	if (str.size() > 10)
	{
		for (size_t i = 0; i < 9; i++)
		{
			std::cout << str[i];
		}
		std::cout << ".";
	}
	else
	{
		int	len = 10 - str.size() + 1;
		std::cout << std::setw(len);
		for (size_t i = 0; i < str.size(); i++)
			std::cout << str[i];
	}
}