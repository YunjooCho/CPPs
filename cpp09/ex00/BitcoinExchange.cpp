/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:11:49 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/29 21:36:18 by yunjcho          ###   ########.fr       */
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

std::list<int> 	BitcoinExchange::split(std::string input, char delimiter)
{
	std::list<int>		result;
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

bool	BitcoinExchange::checkLeafYear(const std::tm& tmDate)
{
	int	targetYear = tmDate.tm_year + 1900;
	
	if ((targetYear % 4 == 0 \
		&& targetYear % 100 != 0) \
		|| targetYear % 400 == 0)
	{
		return (true);
	}
	return (false);
}

bool	BitcoinExchange::checkDate(std::string date)
{
	std::list<int>	result;
	std::tm			tmDate = {};
	
	result = split(date, '-');
	if (result.size() != 3 \
		|| date.find_first_not_of("0123456789-") != std::string::npos)
	{
		return (false);
	}

	std::list<int>::iterator iter = result.begin();
	for (int i = 0; i < 3; i++)
	{
		if ((i == 0 && (*iter < 1900 || *iter > 9999)) \
			|| (i == 1 && (*iter < 1 || *iter > 12)) \
			|| (i == 2 && (*iter < 1 || *iter > 31))
			)
		{
			return (false);
		}
		else if (i == 0)
		{
			tmDate.tm_year = *iter - 1900;
		}
		else if (i == 1)
		{
			tmDate.tm_mon = *iter - 1;
		}
		else if (i == 2)
		{
			tmDate.tm_mday = *iter;
		}
		iter++;
	}
	if (tmDate.tm_mon == 1 && tmDate.tm_mday == 29
		&& !checkLeafYear(tmDate))
		return (false);
	if (std::mktime(&tmDate) == -1)
		return (false);
	return (true);
}

double	BitcoinExchange::checkDBNumber(std::string value)
{
	char	*check = NULL;
	double	doubleVal = std::strtod(value.c_str(), &check);

	if (value.empty() || doubleVal < 0 \
		|| doubleVal > std::numeric_limits<int>::max() \
		|| value.find_first_not_of("0123456789.") != std::string::npos \
		|| strtrim(std::string(check)).empty() == false)
		throw std::runtime_error("Error: invalid value in DataBase. => " + value);
	return (doubleVal);
}

double	BitcoinExchange::checkInputNumber(std::string value)
{
	char	*check = NULL;
	double	doubleVal = std::strtod(value.c_str(), &check);
	
	if (value.find_first_not_of("0123456789.") != std::string::npos \
		|| strtrim(std::string(check)).empty() == false)
	{
		printError(INVALIDNUM, value);
		doubleVal = -1.0;
	}
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
	_readArgs.open(fileName, std::ios::binary);
	if (_readArgs.is_open())
	{
		_readArgs.seekg(0, std::ios::end);
		size_t length = _readArgs.tellg();
		if (length <= 0)
			throw std::runtime_error("Error: database is empty.");
		_readArgs.seekg (0);
		_readArgs.close();
	}
	_readArgs.open(fileName);
	if (_readArgs.is_open())
	{
		std::getline(_readArgs, str);
		str = strtrim(str);
		if (str.compare(headline))
			throw std::runtime_error("Error: The header line is incorrect.");
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
					throw std::runtime_error("Error: cannot found delimiter.");
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
		std::getline(_readArgs, str);
		str = strtrim(str);
		if (str.compare(headline))
		{
			printError(ETC, "Error: The header line is incorrect.");
			return ;
		}
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
					findIdx = 10;
					date = strtrim(str.substr(0, findIdx));
					if (findIdx != str.size())
					{
						value = strtrim(str.substr(findIdx + 1, str.length() - 1));
						if (value.find_first_not_of("0123456789") != std::string::npos)
						{
							printError(INVALIDARG, value);
							continue;
						}
					}
					else
						value = "";
				}
				if (checkDate(date))
				{
					
					double doubleVal = checkInputNumber(value);
					if (doubleVal != -1.0)
					{
						std::map<std::string, double>::iterator iter = _database.lower_bound(date);
						if (iter == _database.end()) //db 보다 큰 날짜면 마지막 날짜로 매핑되도록 함
						{
							iter = --_database.end();
						}
						if (iter->first.compare(date))
						{
							if (iter != _database.begin())
								--iter;
							else
							{
								printError(ETC, date + " doesn't exist in DataBase");
								continue ;
							}
						}
						if (value.compare(""))
						{
							double result = iter->second * doubleVal;
							std::cout << date << " => " << value << " = " << result << std::endl;
						}
						else
							printError(ETC, "Error: value is empty. => " + date);
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
		_readArgs.close();
		std::cout << e.what() << std::endl;
	}
}