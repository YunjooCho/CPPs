/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:54:22 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/08 18:17:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include "PhoneBook.h"
#include "Contact.h"

void	PhoneBook::appendContact(int idx, Contact *contact)
{
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
	for (int i = 0; i < 4; i++)
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
		if ((int)(i + 1) == idx)
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

