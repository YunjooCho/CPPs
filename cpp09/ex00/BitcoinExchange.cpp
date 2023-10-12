/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:11:49 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/12 22:32:27 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange& instance) {}

// BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& instance) {}

void	BitcoinExchange::printError(int errCode, std::string info)
{
	std::string	errMsg = "Error";

	if (errCode == FILEOPENFAIL)
		errMsg = "Error: could not open file.";
	else if (errCode == INVALIDNUM)
		errMsg = "Error: not a positive number.";
	else if (errCode == INVALIDDATE)
	{
		if (!info.empty())
			errMsg = "Error: bad input =>" + info;
		else
			errMsg = "Error: bad input";
	}
	else if (errCode == TOOLARGENUM)
		errMsg = "Error: too large a number.";
	std::cerr << errMsg << std::endl;
}

std::string	BitcoinExchange::ltrim(const std::string &str)
{
	size_t start_idx; 
	
	start_idx = str.find_first_not_of(WHITESPACE);
	return (start_idx == std::string::npos) ? "" : str.substr(start_idx);
}

std::string	BitcoinExchange::rtrim(const std::string &str)
{
	size_t end_idx; 
	
	end_idx = str.find_last_not_of(WHITESPACE);
	return (end_idx == std::string::npos) ? "" : str.substr(0, end_idx + 1);
}

std::string BitcoinExchange::strtrim(const std::string &str)
{
	return rtrim(ltrim(str));
}

bool	BitcoinExchange::checkDate(std::string date)
{
	(void) date;
	return true;
}

bool	BitcoinExchange::checkNumber(std::string	number)
{
	(void) number;
	return true;
}

void	BitcoinExchange::exchange(char *argv)
{
	std::string 	fileName(argv);
	std::string		str;
	std::string		date;
	std::string		value;
	std::size_t		findIdx = 0;

	//1. 파일 유무 및 open 확인
	fileName = strtrim(fileName);
	_readArgs.open(fileName);
	if (_readArgs.is_open())
	{
		//2. 파일 한줄씩 읽어들이면서 파싱
		while (!_readArgs.eof())
		{
			std::getline(_readArgs, str);
			str = strtrim(str);
			// std::cout << "str : " << str << std::endl;
			if (!str.empty() || str.length() > 0)
			{
				if (str.find("|", findIdx) != std::string::npos)
				{
					findIdx = str.find("|", findIdx);
					date = strtrim(str.substr(0, findIdx));
					value = strtrim(str.substr(findIdx + 1, str.length()));
					std::cout << "date : " << date << std::endl;
					std::cout << "value : " << value << std::endl;
					checkDate(date);
					checkNumber(value);
				}
				else
				{
					date = str;
					std::cout << "date2 : " << date << std::endl;
				}
			}
			
		}
		//3. 출력값 저장하기 또는 출력 - outputStream?
	}
	else
		printError(FILEOPENFAIL, fileName);
}