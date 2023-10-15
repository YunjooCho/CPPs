/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:11:49 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/14 14:33:53 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& instance) 
{
	if (this != &instance)
	{
		_database = instance._database;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& instance) 
{
	*this = instance;
}

void	BitcoinExchange::printError(int errCode, std::string info)
{
	std::string	errMsg = "Error";

	if (errCode == FILEOPENFAIL)
		errMsg = "Error: could not open file.";
	else if (errCode == INVALIDNUM)
	{
		if (info.empty())
			errMsg = info;
		else
			errMsg = "Error: invalid number.";
	}
	else if (errCode == INVALIDDATE)
	{
		if (!info.empty())
			errMsg = "Error: bad input => " + info;
		else
			errMsg = "Error: bad input.";
	}
	else if (errCode == INVALIDARG)
	{
		if (!info.empty())
			errMsg = "Error: invalid argument => " + info;
		else
			errMsg = "Error: invalid argument.";
	}
	else if (errCode == ETC)
	{
		if (info.empty())
			errMsg = info;
	}
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

std::vector<int> 	BitcoinExchange::split(std::string input, char delimiter)
{
	std::vector<int>	result;
	std::stringstream	ss(input);
	std::stringstream	ss2;
	std::string			tmp;
	int					val;

	while (std::getline(ss, tmp, delimiter))
	{
		ss2 << tmp;
		ss2 >> val;

		//Debugging
		// std::cout << "val : " << val << std::endl;
		result.push_back(val);
		ss2.clear();
	}
	ss.clear();
	ss.str("");
	ss2.clear();
	ss2.str("");
	return (result);
}

bool	BitcoinExchange::checkDate(std::string date)
{
	std::vector<int>	result;
	std::tm				tmDate;

	result = split(date, '-');
	if (result.size() != 3)
	{
		printError(INVALIDDATE, date);
		return (false);
	}
	if (result[0] < 1900 || result[0] > 9999 || result[1] < 1 || result[1] > 12 || result[2] < 1 || result[2] > 31)
		return (false);
	
	tmDate.tm_year = result[0] - 1900;
	tmDate.tm_mon = result[1] - 1; //0 ~ 11
	tmDate.tm_mday = result[2];
	if (std::mktime(&tmDate) == -1)
		return (false);
	return (true);
}

bool	BitcoinExchange::checkNumber(double doubleVal, int flag)
{
	if (doubleVal < 0)
	{
		printError(INVALIDNUM, "Error: not a positive number. =>" + std::to_string(doubleVal));
		return (false);
	}
	else if ((flag == BTC_INPUT && doubleVal > 1000) || doubleVal > std::numeric_limits<int>::max())
	{
		printError(INVALIDNUM, "Error: too large a number. =>" + std::to_string(doubleVal));
		return (false);
	}
	return (true);
}

void	BitcoinExchange::readFile(std::string fileName, int flag)
{
	std::string		str;
	std::string		date;
	std::string		value;
	std::string		sep;
	std::string		headline;
	std::size_t		findIdx = 0;

	if (flag == BTC_INPUT)
	{
		sep = "|";
		headline = "date | value";
	}
	else if (flag == BTC_DATABASE)
	{
		sep = ",";
		headline = "date,exchange_rate";
	}
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
				findIdx = 0;
				if (!str.compare(headline))
					continue ;
				if (str.find(sep, findIdx) != std::string::npos)
				{
					findIdx = str.find(sep, findIdx);
					date = strtrim(str.substr(0, findIdx));
					value = strtrim(str.substr(findIdx + 1, str.length()));
					std::cout << "date : " << date << std::endl;
					std::cout << "value : " << value << std::endl;
				}
				else
				{
					date = str;
					std::cout << "date2 : " << date << std::endl;
				}
				double	doubleVal = 0.0;
				doubleVal = std::strtod(value.c_str(), NULL); //부동 소수점 변환이 안되므로 >> 로는 제대로 변환 불가
				if (checkDate(date) || checkNumber(doubleVal, flag))
				{
					if (flag == BTC_DATABASE)
						//map 추가
					else
						//계산한 값 출력
				}
				else
				{
					if (flag == BTC_DATABASE)
						break ;
					else
						continue ;
				}
			}
			else
				continue ;
		}
	}
	else
		printError(FILEOPENFAIL, fileName);
}

void	BitcoinExchange::exchange(char *argv)
{
	std::string		database = "data.csv";
	std::string 	fileName(argv);
	(void) argv;
	readFile(database, BTC_DATABASE);
}