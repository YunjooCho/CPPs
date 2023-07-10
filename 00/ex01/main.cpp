/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:36:58 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 18:44:40 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int main(void)
{
	int			idx;
	std::string	num;
	std::string	command;
	PhoneBook	phoneBook;
	Contact		contact;

	idx = 0;
	while (1)
	{
		num = -1;
		std::cout << "-------------- ☎ Phone Book ☎ --------------" << std::endl;
		std::cout << "명령어를 입력해주세요 : (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			phoneBook.createNewContact(&contact, idx);
			phoneBook.appendContact(&contact, idx);
			idx++;
			if (idx == 9)
				idx = 0;
		}
		else if (command == "SEARCH")
		{
			phoneBook.printContacts();
			std::cout << "찾고자 하는 전화번호 정보의 인덱스를 입력하세요 : (숫자)" << std::endl;
			std::getline(std::cin, num);
			meetEof();
			while (std::atoi(num.c_str()) < 1 || std::atoi(num.c_str()) > 8 || num.length() != 1)
			{
				std::cout << "** 유효하지 않은 인덱스 입니다. **" << std::endl;
				std::cin.clear();
				std::cout << "찾고자 하는 전화번호 정보의 인덱스를 입력하세요 : (숫자)" << std::endl;
				std::getline(std::cin, num);
				meetEof();
			}
			if (phoneBook.getContact(std::atoi(num.c_str()))->getFirstName().length() <= 0)
				std::cout << "** 해당 인덱스에 데이터가 존재하지 않습니다. **" << std::endl;
			else
				phoneBook.printOneContact(std::atoi(num.c_str()));
		}
		else if (command == "EXIT")
		{
			std::cout << "** 프로그램을 종료합니다. **" << std::endl;
			break ;
		}
		else
			std::cout << "* 잘못된 명령어입니다. 다시 입력해주세요. *" << std::endl;
		meetEof();
		std::cin.clear();
	}
	return (0);
}
