/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:29:31 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/23 18:10:02 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <vector>
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
		std::vector<int>			split(std::string input, char delimiter);
		bool						checkDate(std::string date);
		bool						checkNumber(double number, int flag);
		// std::string					createClosestDate(std::string date, std::string minDate);
		// int							calculateDates(std::string date);
		// std::string					compareDates(std::string inputDate);
		void						readDataBaseFile(std::string fileName);
		void						readInputFile(std::string fileName);
};

#endif