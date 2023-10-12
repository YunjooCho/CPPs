/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:29:31 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/12 22:17:20 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>

const std::string WHITESPACE = " \n\r\t\f\v";

enum errInfo
{
	FILEOPENFAIL,
	INVALIDNUM,
	INVALIDDATE,
	TOOLARGENUM
};

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void		exchange(char *fileName);
		void		printError(int errCode, std::string info);
	private:
		// int	_errCode;		// 에러코드에 띠른 출력 메시지
		std::ifstream	_readDataBase;
		std::ifstream	_readArgs;
		BitcoinExchange(const BitcoinExchange& instance);
		BitcoinExchange& operator=(const BitcoinExchange& instance);
		std::string	ltrim(const std::string &str);
		std::string	rtrim(const std::string &str);
		std::string	strtrim(const std::string &str);
		bool		checkDate(std::string date);
		bool		checkNumber(std::string	number);
};

#endif