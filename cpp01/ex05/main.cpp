/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:44:12 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/05 20:50:58 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	level;
	Harl		*harl;

	harl = new Harl;
	while (1)
	{
		std::cout << "Please input level (Only Upper Case) : " << std::endl;
		std::getline(std::cin, level);
		if (std::cin.eof())
		{
			clearerr(stdin);
			std::cin.clear();
			break ;
		}
		harl->complain(level);
		std::cin.clear();
	}
	delete harl;
	return (0);
}