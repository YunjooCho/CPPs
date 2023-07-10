/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:36:58 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 16:04:06 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.h"

char	*upper_string(char *str)
{
	for (size_t i = 0; i < strlen(str); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

void	clear_buffer(void)
{
	if (std::cin.eof()) 
	{
		clearerr(stdin);
		std::cin.clear();
	}
	else 
	{
		std::cin.clear();
		std::cin.ignore(10000,'\n');
	}
}

int main(void)
{
	int			idx;
	int			num;
	char		*command;
	char		*command_upper;
	PhoneBook	phoneBook;
	Contact		contact;

	idx = 0;
	command = NULL;
	command_upper = NULL;
	while (1)
	{
		num = -1;
		std::cout << "-------------- ☎ Phone Book ☎ --------------" << std::endl;
		std::cout << "명령어를 입력해주세요 : (ADD, SEARCH, EXIT)" << std::endl;
		std::cin.getline(command, 10000);
		command_upper = upper_string(command);
		if (!strcmp(command_upper,"ADD"))
		{
			contact.createNewContact(&contact, idx);
			phoneBook.appendContact(idx, &contact);
			idx++;
			if (idx == 9)
				idx = 0;
			clear_buffer();
		}
		else if (!strcmp(command_upper,"SEARCH"))
		{
			phoneBook.printContacts();
			std::cout << "찾고자 하는 전화번호 정보의 인덱스를 입력하세요 : (숫자)" << std::endl;
			std::cin >> num;
			while (num < 1 || num > 8)
			{
				std::cout << "** 유효하지 않은 인덱스 입니다. **" << std::endl;
				clear_buffer();
				std::cout << "찾고자 하는 전화번호 정보의 인덱스를 입력하세요 : (숫자)" << std::endl;
				std::cin >> num;
			}
			if (phoneBook.getContact(num)->getFirstName().length() <= 0)
			{
				std::cout << "** 해당 인덱스에 데이터가 존재하지 않습니다. **" << std::endl;
				clear_buffer();
			}
			else
				phoneBook.printOneContact(idx);
			clear_buffer();
		}
		else if (!strcmp(command_upper,"EXIT"))
		{
			std::cout << "** 프로그램을 종료합니다. **" << std::endl;
			break ;
		}
		else
			std::cout << "* 잘못된 명령어입니다. 다시 입력해주세요. *" << std::endl;
		clear_buffer();
	}
	return (0);
}
