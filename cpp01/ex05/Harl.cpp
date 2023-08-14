/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:02:50 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/14 17:37:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my " 
		<< "7XL-double-cheese-triple-pickle-specialketchup burger. "
		<< "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
		<< "You didn’t put enough bacon in my burger! "
		<< "If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra "
		<< "bacon for free. I’ve been coming for years whereas you started "
		<< "working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unaCXXeptable! I want to speak to "
		<< "the manager now." << std::endl;
}

std::string	Harl::stringToUppercase(std::string level)
{
	for (size_t i = 0; i < level.length(); i++)
	{
		level[i] = std::toupper(level[i]);
	}
	return (level);
} 

void	Harl::complain(std::string level)
{
	int		result;
	t_codes codes[4] = {
		{"DEBUG", DEBUG}, {"INFO", INFO}, {"WARNING", WARNING}, {"ERROR", ERROR}
	};

	result = -1;
	funPtr[0] = &Harl::debug;
	funPtr[1] = &Harl::info;
	funPtr[2] = &Harl::warning;
	funPtr[3] = &Harl::error;
	if (!level.empty())
		level = stringToUppercase(level);
	for (int i = 0; i < 4; i++)
	{
		if (!std::strcmp(level.c_str(), codes[i].key.c_str()))
		{
			(this->*funPtr[i])();
			return ;
		}
	}
	std::cout << "Invalid Level" << std::endl;
	exit(1);
}