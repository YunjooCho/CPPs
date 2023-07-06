/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:36:58 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/06 20:42:44 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.h"
#include "Contact.h"

int main(void)
{
	int			idx;
	std::string	command;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	PhoneBook	phoneBook;
	Contact		contact;

	idx = 0;
	while (1)
	{
		std::cout << "커맨드를 입력해주세요 : (ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> command;
		if (command == "ADD")
		{
			std::cout << idx << ")) 이름을 입력하세요 : " << std::endl;
			std::cin >> firstName;
			std::cout << idx << ")) 성을 입력하세요 : " << std::endl;
			std::cin >> lastName;
			std::cout << idx << ")) 별명을 입력하세요 : " << std::endl;
			std::cin >> nickname;
			std::cout << idx << ")) 전화번호를 입력하세요 : " << std::endl;
			std::cin >> phoneNumber;
			std::cout << idx << ")) 비밀을 입력하세요 : " << std::endl;
			std::cin >> darkestSecret;
			contact.setVariables(idx, firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.appendContact(idx, &contact);
			idx++;
			if (idx == 9)
				idx = 0;
			std::cout << "* 입력이 완료 되었습니다. *" << std::endl;
		}
		else if (command == "SEARCH")
		{
			phoneBook.printContacts();
		}
		else if (command == "EXIT")
		{
			std::cout << "* 프로그램을 종료합니다. *" << std::endl;
			break ;
		}
		else
		{
			std::cout << "* 잘못된 명령어입니다. 다시 입력해주세요. *" << std::endl;
		}
	}
	return (0);
}