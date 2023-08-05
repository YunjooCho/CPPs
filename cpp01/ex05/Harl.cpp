/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:02:50 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/05 20:48:50 by yunjcho          ###   ########.fr       */
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
	std::cout << "This is unacceptable! I want to speak to "
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
	int	result = -1;
	t_codes codes[4] = {
		{"DEBUG", DEBUG}, {"INFO", INFO}, {"WARNING", WARNING}, {"ERROR", ERROR}
	};

	if (!level.empty())
		level = stringToUppercase(level);
	for (int i = 0; i < 4; i++)
	{
		if (!std::strcmp(level.c_str(), codes[i].key.c_str()))
		{
			result = codes[i].val;
			break ;
		}
	}
	
	switch (result)
	{
		case DEBUG:
			this->debug();
			break ;
		case INFO:
			this->info();
			break ;
		case WARNING:
			this->warning();
			break ;
		case ERROR:
			this->error();
			break ;
		case -1:
			exit(1);
	}
}