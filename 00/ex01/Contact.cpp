/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:51:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/08 21:27:39 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.h"


void	Contact::createNewContact(Contact *contact, int idx)
{
	int			result;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << idx << ")) 이름을 입력하세요 : " << std::endl;
	std::cin >> firstName;
	if (firstName.length() <= 0 || std::cin.eof() == true)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		std::clearerr(stdin); //EOF 와 오류 표시자를 재설정
		std::cin.clear();     //표준 입력 버퍼 비우기
	}
	std::cout << idx << ")) 성을 입력하세요 : " << std::endl;
	std::cin >> lastName;
	if (lastName.length() <= 0 || std::cin.eof() == true)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		std::clearerr(stdin); //EOF 와 오류 표시자를 재설정
		std::cin.clear();     //표준 입력 버퍼 비우기
	}
	std::cout << idx << ")) 별명을 입력하세요 : " << std::endl;
	std::cin >> nickname;
	if (nickname.length() <= 0 || std::cin.eof() == true)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		std::clearerr(stdin); //EOF 와 오류 표시자를 재설정
		std::cin.clear();     //표준 입력 버퍼 비우기
	}
	std::cout << idx << ")) 전화번호를 입력하세요 : " << std::endl;
	std::cin >> phoneNumber;
	if (phoneNumber.length() <= 0 || std::cin.eof() == true)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		std::clearerr(stdin); //EOF 와 오류 표시자를 재설정
		std::cin.clear();     //표준 입력 버퍼 비우기
	}
	result = std::atoi(phoneNumber.c_str());
	std::cout << result << std::endl;

	std::cout << idx << ")) 비밀을 입력하세요 : " << std::endl;
	std::cin >> darkestSecret;
	if (darkestSecret.length() <= 0 || std::cin.eof() == true)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		std::clearerr(stdin); //EOF 와 오류 표시자를 재설정
		std::cin.clear();     //표준 입력 버퍼 비우기
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