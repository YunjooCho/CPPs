/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:10:22 by yunjcho           #+#    #+#             */
/*   Updated: 2023/06/18 20:14:36 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
	int	idx1;
	int	idx2;

	idx1 = 1;
	idx2 = 0;
	if (ac > 1)
	{
		idx1 = 1;
		while (av[idx1])
		{
			idx2 = 0;
			while (av[idx1][idx2])
			{
				av[idx1][idx2] = std::toupper(av[idx1][idx2]);
				std::cout << av[idx1][idx2];
				idx2++;
			}
			idx1++;
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
