/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:31:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/14 18:43:53 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename(av[1]);
		std::string s1(av[2]);
		std::string s2(av[3]);

		if (!filename.empty() && !s1.empty() && !s2.empty())
		{
			fout.open(filename);
		}
		else
			std::cout << "Invalid arguments existed" << std::endl;
	}
	else
		std::cout << "Please put in 3 parameters" << std::endl;
	return (0);
}