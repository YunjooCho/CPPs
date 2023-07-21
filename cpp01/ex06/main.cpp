/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:24:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/21 15:52:04 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	*harl;

	harl = new Harl();
	if (ac == 2)
	{
		if (av[1] && std::strlen(av[1]) >= 0)
			harl->complain(av[1]);
		else
			std::cout << "Invalid String" << std::endl;
	}
	else
		std::cout << "Invalid Argument Count" << std::endl;
	delete harl;
	return (0);
}