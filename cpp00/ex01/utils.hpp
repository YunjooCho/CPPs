/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 12:48:01 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/24 19:28:49 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "PhoneBook.hpp"
# include "Contact.hpp"

const std::string WHITESPACE = " \n\r\t\f\v";

std::string	upperString(std::string str);
void		meetEof(void);
std::string	ltrim(const std::string &str);
std::string	rtrim(const std::string &str);
std::string	strtrim(const std::string &str);

#endif