/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:36:58 by yunjcho           #+#    #+#             */
/*   Updated: 2023/06/18 20:46:02 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string	command;

	while (1)
	{
		getline(std::cin, command);
		std::cout << command << std::endl;
		if (command == "ADD")
			std::cout << "ADD";
		else if (command == "SEARCH")
			std::cout << "SEARCH";
		else if (command == "EXIT")
		{
			std::cout << "EXIT";
			break ;
		}
	}
	return (0);
}