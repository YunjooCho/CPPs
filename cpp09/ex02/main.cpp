/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:32:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/24 22:43:44 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	if (ac >= 2)
	{
		PmergeMe sort;

		try
		{
			sort.parsing(av);
			//sort.sort();
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
	}
	else
		std::cout << "Error: not enough argument count." << std::endl;
	return (0);
}