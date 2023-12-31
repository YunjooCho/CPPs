/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:32:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/28 12:43:44 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char** av)
{
	BitcoinExchange exchange;

	if (ac == 2)
		exchange.exchange(av[1]);
	else
		exchange.printError(FILEOPENFAIL, "");
	return (0);
}