/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:54:22 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/06 20:52:35 by yunjcho          ###   ########.fr       */
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
	return &contactArr[idx];
}

void	PhoneBook::printContacts(void)
{
	std::cout << std::setw(10);
	std::cout << "  Index  || First Name ||  Last Name  ||   Nickname  ||" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << std::setw(10);
		std::cout << i + 1  \
			<< contactArr[i].getFirstName() \
			<< contactArr[i].getLasttName() \
			<< contactArr[i].getNickname() \
			<< std::endl;
	}
}
