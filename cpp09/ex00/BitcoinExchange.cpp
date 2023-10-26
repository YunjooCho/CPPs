/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:11:49 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/26 18:52:16 by yunjcho          ###   ########.fr       */
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
		errMsg = info;
	}
	std::cout << errMsg << std::endl;
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
	std::tm				tmDate = {};
	
	result = split(date, '-');
	if (result.size() != 3)
	{
		printError(INVALIDDATE, date);
		return (false);
	}
	if (result[0] < 1900 || result[0] > 9999 || result[1] < 1 || result[1] > 12 || result[2] < 1 || result[2] > 31)
		return (false);
	tmDate.tm_year = result[0] - 1900;
	tmDate.tm_mon = result[1] - 1;
	tmDate.tm_mday = result[2];
	if (std::mktime(&tmDate) == -1)
		return (false);
	return (true);
}

double	BitcoinExchange::checkDBNumber(std::string value)
{
	double	doubleVal = std::strtod(value.c_str(), NULL);
	if (value.empty() || doubleVal < 0 || doubleVal > std::numeric_limits<int>::max())
		throw std::runtime_error("Error: invalid value in DataBase. => " + value);
	return (doubleVal);
}

double	BitcoinExchange::checkInputNumber(std::string value)
{
	double	doubleVal = std::strtod(value.c_str(), NULL);
	if (value.empty())
		doubleVal = -1.0;
	else if (doubleVal < 0)
	{
		printError(ETC, "Error: not a positive number.");
		doubleVal = -1.0;
	}
	else if (doubleVal > 1000)
	{
		printError(ETC, "Error: too large a number.");
		doubleVal = -1.0;
	}
	return (doubleVal);
}

void	BitcoinExchange::readDataBaseFile(std::string fileName)
{
	const std::string	sep = ",";
	const std::string	headline = "date,exchange_rate";
	std::string			str;
	std::string			date;
	std::string			value;
	std::size_t			findIdx = 0;

	fileName = strtrim(fileName);
	_readArgs.open(fileName);
	if (_readArgs.is_open())
	{
		while (!_readArgs.eof())
		{
			std::getline(_readArgs, str);
			str = strtrim(str);
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
				}
				else
				{
					date = str;
				}
				if (checkDate(date))
				{
					double doubleVal = checkDBNumber(value);
					_database.insert(std::pair<std::string, double>(date, doubleVal));
				}
				else
					throw std::runtime_error("Error: invalid date in DataBase. => " + date); //continue;
			}
			else
				continue ;
		}
	}
	else
		throw std::runtime_error("Error: " + fileName + "can't open the file.");
	_readArgs.close();
}

void	BitcoinExchange::readInputFile(std::string fileName)
{
	const std::string	sep = "|";
	const std::string	headline = "date | value";
	std::string			str;
	std::string			date;
	std::string			value;
	std::size_t			findIdx = 0;

	fileName = strtrim(fileName);
	_readArgs.open(fileName);
	if (_readArgs.is_open())
	{
		while (!_readArgs.eof())
		{
			std::getline(_readArgs, str);
			str = strtrim(str);
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
				}
				else
				{
					date = str;
				}
				if (checkDate(date))
				{
					double doubleVal = checkInputNumber(value);
					if (doubleVal != -1.0)
					{
						std::map<std::string, double>::iterator iter = _database.lower_bound(date);
						if (iter->first.compare(date))
						{
							if (iter != _database.begin())
								--iter;
							else
							{
								printError(ETC, date + "doesn't exist invalid date in DataBase");
								continue ;
							}
						}
						double result = iter->second * doubleVal;
						std::cout << date << " => " << value << " = " << result << std::endl;
					}
					
				}
				else
				{
					printError(INVALIDDATE, date);
					continue ;
				}
			}
			else
				continue ;
		}
	}
	else
		throw std::runtime_error("Error: " + fileName + " can't open the file.");
	_readArgs.close();
}

void	BitcoinExchange::exchange(char *argv)
{
	std::string		database = "data.csv";
	std::string 	fileName(argv);

	try
	{
		readDataBaseFile(database);
		readInputFile(fileName);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}