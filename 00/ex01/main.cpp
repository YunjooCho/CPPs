/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:36:58 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/08 21:13:51 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.h"
#include "Contact.h"

std::string	upper_string(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

int main(void)
{
	int			idx;
	int			num;
	std::string	command;
	std::string	command_upper;
	PhoneBook	phoneBook;
	Contact		contact;

	idx = 0;
	while (1)
	{
		num = -1;
		std::cout << "-------------- ☎ Phone Book ☎ --------------" << std::endl;
		std::cout << "명령어를 입력해주세요 : (ADD, SEARCH, EXIT)" << std::endl;
		getline(std::cin, command);
		command_upper = upper_string(command);
		if (command_upper == "ADD")
		{
			if (std::cin.eof() == true || std::cin)
			{
				std::clearerr(stdin); //EOF 와 오류 표시자를 재설정
				std::cin.clear();     //표준 입력 버퍼 비우기
			}
			contact.createNewContact(&contact, idx);
			phoneBook.appendContact(idx, &contact);
			idx++;
			if (idx == 9)
				idx = 0;
		}
		else if (command_upper == "SEARCH")
		{
			phoneBook.printContacts();
			std::cout << "찾고자 하는 전화번호 정보의 인덱스를 입력하세요 : (숫자)" << std::endl;
			std::cin >> num;
			if (num < 1 || num > 8)
			{
				std::cout << "** 유효하지 않은 인덱스 입니다. **" << std::endl;
				std::clearerr(stdin); //EOF 와 오류 표시자를 재설정
				std::cin.clear();     //표준 입력 버퍼 비우기
			}
			else
			{
				if (phoneBook.getContact(num)->getFirstName().length() <= 0)
					std::cout << "** 해당 인덱스에 데이터가 존재하지 않습니다. **" << std::endl;
				else
					phoneBook.printOneContact(idx);
			}
		}
		else if (command_upper == "EXIT")
		{
			std::cout << "** 프로그램을 종료합니다. **" << std::endl;
			break ;
		}
		else
			std::cout << "* 잘못된 명령어입니다. 다시 입력해주세요. *" << std::endl;
		if (std::cin.eof() == true)
		{
			std::clearerr(stdin); //EOF 와 오류 표시자를 재설정
			std::cin.clear();     //표준 입력 버퍼 비우기
		}
	}
	return (0);
}
