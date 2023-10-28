/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:29:31 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/28 18:31:55 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <list>
# include <ctime>
# include <algorithm>

const std::string WHITESPACE = " \n\r\t\f\v";

enum errInfo
{
	FILEOPENFAIL,
	INVALIDNUM,
	INVALIDDATE,
	INVALIDARG,
	ETC
};

enum fileInfo
{
	BTC_DATABASE,
	BTC_INPUT
};

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		void		exchange(char *fileName);
		void		printError(int errCode, std::string info);
	private:
		std::ifstream					_readDataBase;
		std::ifstream					_readArgs;
		std::map<std::string, double>	_database;
		BitcoinExchange(const BitcoinExchange& instance);
		BitcoinExchange& operator=(const BitcoinExchange& instance);
		std::string					ltrim(const std::string &str);
		std::string					rtrim(const std::string &str);
		std::string					strtrim(const std::string &str);
		std::list<int>				split(std::string input, char delimiter);
		bool						checkLeafYear(const std::tm& tmDate);
		bool						checkDate(std::string date);
		double						checkDBNumber(std::string value);
		double						checkInputNumber(std::string value);
		void						readDataBaseFile(std::string fileName);
		void						readInputFile(std::string fileName);
};

#endif