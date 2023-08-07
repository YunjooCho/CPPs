/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:37:16 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/07 14:39:46 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "utils.hpp"

std::string	ltrim(const std::string &str)
{
	size_t start_idx; 
	
	start_idx = str.find_first_not_of(WHITESPACE);
	return (start_idx == std::string::npos) ? "" : str.substr(start_idx);
}

std::string	rtrim(const std::string &str)
{
	size_t end_idx; 
	
	end_idx = str.find_last_not_of(WHITESPACE);
	return (end_idx == std::string::npos) ? "" : str.substr(0, end_idx + 1);
}

std::string strtrim(const std::string &str)
{
	return rtrim(ltrim(str));
}