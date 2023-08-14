/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 14:39:02 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/14 14:25:02 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iomanip>
# include <string>
#include <fstream>

const std::string WHITESPACE = " \n\r\t\f\v";

std::string	ltrim(const std::string &str);
std::string	rtrim(const std::string &str);
std::string	strtrim(const std::string &str);

#endif