/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:51:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 16:04:27 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

int	check_phoneNumber(std::string phoneNumber)
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
	char	*firstName = NULL;
	char	*lastName = NULL;
	char	*nickname = NULL;
	char	*phoneNumber = NULL;
	char	*darkestSecret = NULL;

	std::cout << idx << ")) 이름을 입력하세요 : " << std::endl;
	std::cin.getline(firstName, 10000);
	// std::cin >> firstName;
	while (strlen(firstName) <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		clear_buffer();
		std::cout << idx << ")) 이름을 입력하세요 : " << std::endl;
		std::cin.getline(firstName, 10000);
		// std::cin >> firstName;
	}
	std::cout << idx << ")) 성을 입력하세요 : " << std::endl;
	std::cin.getline(lastName, 10000);
	// std::cin >> lastName;
	while (strlen(lastName) <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		clear_buffer();
		std::cout << idx << ")) 성을 입력하세요 : " << std::endl;
		std::cin >> lastName;
	}
	std::cout << idx << ")) 별명을 입력하세요 : " << std::endl;
	std::cin.getline(nickname, 10000);
	// std::cin >> nickname;
	while (strlen(nickname) <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		clear_buffer();
		std::cout << idx << ")) 별명을 입력하세요 : " << std::endl;
		std::cin.getline(nickname, 10000);
		// std::cin >> nickname;
	}
	std::cout << idx << ")) 전화번호를 입력하세요 : ('-'는 제외)" << std::endl;
	std::cin.getline(phoneNumber, 10000);
	//std::cin >> phoneNumber;
	while (strlen(phoneNumber) <= 0 || check_phoneNumber(phoneNumber) == 0)
	{	
		if (strlen(phoneNumber) <= 0)
			std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		else
		{
			if (!check_phoneNumber(phoneNumber))
				std::cout << "** 전화번호가 유효하지 않습니다. **" << std::endl;
			else
				break;
		}
		clear_buffer();
		std::cout << idx << ")) 전화번호를 입력하세요 : " << std::endl;
		std::cin.getline(phoneNumber, 10000);
		//std::cin >> phoneNumber;
	}
	std::cout << idx << ")) 비밀을 입력하세요 : " << std::endl;
	std::cin.getline(darkestSecret, 10000);
	// std::cin >> darkestSecret;
	while (strlen(darkestSecret) <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		clear_buffer();
		std::cout << idx << ")) 비밀을 입력하세요 : " << std::endl;
		std::cin.getline(darkestSecret, 10000);
		// std::cin >> darkestSecret;
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