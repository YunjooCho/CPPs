/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:54:39 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 18:06:24 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

std::string	upperString(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	return (str);
}

void	meetEof(void)
{
	if (std::cin.eof()) 
	{
		clearerr(stdin);
		std::cin.clear();
	}
}