/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:33:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/19 22:52:10 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <stdio.h> //TODO - delete

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::string argv(av[1]);
		ScalarConverter::convert(argv);
	}
	return (0);
}
