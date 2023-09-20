/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:33:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/20 20:28:29 by yunjcho          ###   ########seoul.kr  */
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
