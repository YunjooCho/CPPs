/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:54:22 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/17 15:32:17 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

int	PhoneBook::checkPhoneNumber(std::string phoneNumber)
{
	for (int i = 0; i < (int)phoneNumber.length(); i++)
	{
		if (phoneNumber[i] < '0' || phoneNumber[i] > '9')
			return (0);
	}
	return (1);
}

void	PhoneBook::createNewContact(Contact *contact, int idx)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << idx + 1 << ")) 이름을 입력하세요 : " << std::endl;
	std::getline(std::cin, firstName);
	meetEof();
	while (firstName.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cin.clear();
		std::cout << idx + 1 << ")) 이름을 입력하세요 : " << std::endl;
		std::getline(std::cin, firstName);
	}
	std::cout << idx + 1 << ")) 성을 입력하세요 : " << std::endl;
	std::getline(std::cin, lastName);
	meetEof();
	while (lastName.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cin.clear();
		std::cout << idx + 1 << ")) 성을 입력하세요 : " << std::endl;
		std::getline(std::cin, lastName);
	}
	std::cout << idx + 1 << ")) 별명을 입력하세요 : " << std::endl;
	std::getline(std::cin, nickname);
	meetEof();
	while (nickname.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cin.clear();
		std::cout << idx + 1 << ")) 별명을 입력하세요 : " << std::endl;
		std::getline(std::cin, nickname);
	}
	std::cout << idx + 1 << ")) 전화번호를 입력하세요 : ('-' 제외)" << std::endl;
	std::getline(std::cin, phoneNumber);
	meetEof();
	while (phoneNumber.length() <= 0 || checkPhoneNumber(phoneNumber) == 0)
	{	
		std::cin.clear();
		if (phoneNumber.length() <= 0)
			std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		if (!checkPhoneNumber(phoneNumber))
			std::cout << "** 전화번호가 유효하지 않습니다. **" << std::endl;
		else
			break;
		std::cout << idx + 1 << ")) 전화번호를 입력하세요 : ('-' 제외)" << std::endl;
		std::getline(std::cin, phoneNumber);
	}
	std::cout << idx + 1 << ")) 비밀을 입력하세요 : " << std::endl;
	std::getline(std::cin, darkestSecret);
	meetEof();
	while (darkestSecret.length() <= 0)
	{
		std::cout << "** 아무 것도 입력되지 않았습니다. 다시 입력해 주세요. ** " << std::endl;
		meetEof();
		std::cin.clear();
		std::cout << idx + 1 << ")) 비밀을 입력하세요 : " << std::endl;
		std::getline(std::cin, darkestSecret);
	}
	std::cout << "** 입력이 완료 되었습니다. **" << std::endl;
	contact->setVariables(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

void	PhoneBook::appendContact(Contact *contact, int idx)
{
	idx %= 8;
	contactArr[idx] = *contact;
}

Contact *PhoneBook::getContact(int idx)
{
	if (idx >= 1 && idx <= 8)
		return &contactArr[idx - 1];
	else
		return NULL;
}

void	PhoneBook::printContacts(void)
{
	std::cout << std::setw(10) << "Index" << " | " \
		<< std::setw(10) << "First Name" << " | " \
		<< std::setw(10) << "Last Name" << " | " \
		<< std::setw(10) << "Nickname" << " | " << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!contactArr[i].getFirstName().empty())
		{
			std::cout << std::setw(10) << i + 1 << " | ";
			contactArr[i].chagePrintString(contactArr[i].getFirstName());
			std::cout << " | ";
			contactArr[i].chagePrintString(contactArr[i].getLastName());
			std::cout << " | ";
			contactArr[i].chagePrintString(contactArr[i].getNickname());
			std::cout << " | " << std::endl;
		}
	}
}

void	PhoneBook::printOneContact(int idx)
{
	for (size_t	i = 0; i < sizeof contactArr; i++)
	{
		if ((int)i == idx - 1)
		{
			std::cout << "Index : " << idx << std::endl;
			std::cout << "First Name : " << contactArr[i].getFirstName() << std::endl;
			std::cout << "Last Name : " << contactArr[i].getLastName() << std::endl;
			std::cout << "Nickname : " << contactArr[i].getNickname() << std::endl;
			std::cout << "Phone Number : " << contactArr[i].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret : " << contactArr[i].getDarkestSecret() << std::endl;
			break ;
		}
	}
	
}

