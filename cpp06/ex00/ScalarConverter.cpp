/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:58:51 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/15 21:21:26 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int 		ScalarConverter::_argvType = -1;
std::string	ScalarConverter::_convertChar = "";
std::string	ScalarConverter::_convertInt = "";
std::string	ScalarConverter::_convertFloat = "";
std::string	ScalarConverter::_convertDouble = "";

/*
//static Class는 생성자와 소멸자를 정의 할 수 없음
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &form) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &form) {}
ScalarConverter::~ScalarConverter() {}
*/

bool	ScalarConverter::checkArgsPseudo(std::string &argv)
{
	std::string	float_pseudos[6] = {"-inff", "+inff", "inff", "-nanf", "+nanf", "nanf"};
	std::string	double_pseudos[6] = {"-inf", "+inf", "inf", "-nan", "+nan", "nan"};

	for (size_t i = 0; i < 6; i++)
	{
		if (!argv.compare(float_pseudos[i]))
		{
			_convertChar = "impossible";
			_convertInt = "impossible";
			_convertFloat = float_pseudos[i];
			_convertDouble = double_pseudos[i];
			_argvType = i;
			return (true);
		}
	}
	for (size_t i = 0; i < 6; i++)
	{
		if (!argv.compare(double_pseudos[i]))
		{
			_convertChar = "impossible";
			_convertInt = "impossible";
			_convertFloat = float_pseudos[i];
			_convertDouble = double_pseudos[i];
			_argvType = i;
			return (true);
		}
	}
	return (false);
}

int	ScalarConverter::checkArgsType(std::string &argv)
{
	const std::string	NUMBERS = "0123456789";

	if (argv.length() == 1 && argv.find_first_of(NUMBERS) == std::string::npos)
	{
		if (argv.c_str()[0] >= 0 && argv.c_str()[0] <= 127)
			return (CHAR_TYPE);
	}
	else
	{
		if (argv.find_first_of(NUMBERS) != std::string::npos)
		{
			if (argv.find(".") != std::string::npos)
			{
				int	idx = argv.find(".");
				if (idx == 0 || idx == static_cast<int>(argv.length() - 1) || argv.find(".", idx + 1) != std::string::npos)
					return (ETC_TYPE);
				if (argv.find_last_of("f") == (argv.length() - 1))
				{
					std::string	tmp = argv.erase(argv.find_last_of("f"));
					if (tmp.find("f") != std::string::npos)
						return (ETC_TYPE);
					return (FLOAT_TYPE);
				}
				return (DOUBLE_TYPE);
			}
			return (INT_TYPE);
		}
		if (argv.length() == 2 && argv.c_str()[0] == '-')
			return (CHAR_TYPE);
	}
	return (ETC_TYPE);
}

void	ScalarConverter::convertChar(std::string &argv)
{
	std::stringstream	charStream;
	int					charIntVal = 0;

	if (argv.length() == 2 && argv.c_str()[0] == '-')
	{
		charIntVal = static_cast<int>(argv.c_str()[1]);
		charIntVal *= -1;
	}
	else
	{
		charIntVal = static_cast<int>(argv.c_str()[0]);
	}

	if (charIntVal > std::numeric_limits<char>::max() \
		|| charIntVal < std::numeric_limits<char>::min())
		_convertChar = "impossible";
	else if (charIntVal >= ' ' && charIntVal <= '~')
		_convertChar = static_cast<char>(charIntVal);
	else
		_convertChar = "Non displayable";
	_convertInt = std::to_string(charIntVal);
	charStream << std::fixed << std::setprecision(1) << static_cast<float>(charIntVal);
	std::string convertStr = charStream.str();
	_convertFloat = convertStr + "f";
	_convertDouble = convertStr;

	charStream.str("");
	charStream.clear();
}

void	ScalarConverter::convertInt(std::string &argv)
{
	std::stringstream	convertIntStream(argv);
	std::stringstream	intStream;
	int					intVal = 0;
	double				doubleVal = 0.0;

	convertIntStream >> intVal;
	doubleVal = std::strtod(argv.c_str(), NULL);

	if (intVal > std::numeric_limits<char>::max() \
		|| intVal < std::numeric_limits<char>::min())
		_convertChar = "impossible";
	else if (intVal >= ' ' && intVal <= '~')
		_convertChar = static_cast<char>(intVal);
	else
		_convertChar = "Non displayable";

	if (doubleVal > std::numeric_limits<int>::max() \
		|| doubleVal < std::numeric_limits<int>::min())
	{
		_convertInt = "impossible";
		_convertFloat = "impossible";
		_convertDouble = "impossible";
	}
	else
	{
		_convertInt = std::to_string(intVal);
		intStream << std::fixed << std::setprecision(1) << doubleVal;
		std::string convertStr = intStream.str();
		_convertFloat = convertStr + "f";
		_convertDouble = convertStr;
	}
	convertIntStream.str("");
	convertIntStream.clear();
	intStream.str("");
	intStream.clear();
}

void	ScalarConverter::convertFloat(std::string &argv)
{
	std::stringstream	floatStream;
	int					intVal = 0;
	float				floatVal = 0.0;
	double 				doubleVal = 0.0;

	floatVal = std::strtof(argv.c_str(), NULL);
	doubleVal = std::strtod(argv.c_str(), NULL);
	intVal = static_cast<int>(floatVal);
	if (intVal > std::numeric_limits<char>::max() \
		|| intVal < std::numeric_limits<char>::min())
		_convertChar = "impossible";
	else if (intVal >= ' ' && intVal <= '~')
		_convertChar = static_cast<char>(intVal);
	else
		_convertChar = "Non displayable";
	if (doubleVal > std::numeric_limits<int>::max() \
		|| doubleVal < std::numeric_limits<int>::min())
	{
		_convertInt = "impossible";
	}
	else
	{
		_convertInt = std::to_string(intVal);
	}
	if (argv.find("e") != std::string::npos || argv.substr(argv.find("."), argv.length()).length() > 2)
		floatStream << floatVal;
	else
		floatStream << std::fixed << std::setprecision(1) << floatVal;
	std::string convertStr = floatStream.str();
	_convertFloat = convertStr + "f";
	_convertDouble = convertStr;

	std::cout << convertStr.compare(argv.substr(0, convertStr.length())) << std::endl;
	
	if (convertStr.compare(argv.substr(0, convertStr.length())) || ((doubleVal > std::numeric_limits<float>::max() \
		|| doubleVal < std::numeric_limits<float>::min())
		&& floatVal != 0.0))
	{	
		_convertInt = "impossible";
		_convertFloat  = "impossible";
		_convertDouble = "impossible";
	}
	floatStream.str("");
	floatStream.clear();
}

void	ScalarConverter::convertDouble(std::string &argv)
{
	std::stringstream	doubleStream;
	int					intVal = 0;
	float				floatVal = 0.0;
	double 				doubleVal = 0.0;
	long double			longDoubleVal = 0.0;

	floatVal = std::strtof(argv.c_str(), NULL);
	doubleVal = std::strtod(argv.c_str(), NULL);
	longDoubleVal = std::strtold(argv.c_str(), NULL);
	intVal = static_cast<int>(doubleVal);
	if (intVal > std::numeric_limits<char>::max() \
		|| intVal < std::numeric_limits<char>::min())
		_convertChar = "impossible";
	else if (intVal >= ' ' && intVal <= '~')
		_convertChar = static_cast<char>(intVal);
	else
		_convertChar = "Non displayable";
	if (doubleVal > std::numeric_limits<int>::max() \
		|| doubleVal < std::numeric_limits<int>::min())
	{
		_convertInt = "impossible";
	}
	else
	{
		_convertInt = std::to_string(intVal);
	}
	if (argv.find("e") != std::string::npos || argv.substr(argv.find("."), argv.length()).length() > 2)
		doubleStream << doubleVal;
	else
		doubleStream << std::fixed << std::setprecision(1) << doubleVal;
	std::string convertStr = doubleStream.str();
	_convertFloat = convertStr + "f";
	_convertDouble = convertStr;

	if ((doubleVal > std::numeric_limits<float>::max() \
		|| doubleVal < std::numeric_limits<float>::min()) \
		&& floatVal != 0.0)
	{
		_convertFloat = "impossible";
	}

	std::cout << argv << std::endl;
	std::cout << convertStr << std::endl;
	std::cout << convertStr.compare(argv.substr(0, convertStr.length())) << std::endl;
	
	if (convertStr.compare(argv.substr(0, convertStr.length())) \
		|| ((longDoubleVal > std::numeric_limits<double>::max() \
		|| longDoubleVal < std::numeric_limits<double>::min())
		&& floatVal != 0.0))
	{	
		_convertInt = "impossible";
		_convertFloat = "impossible";
		_convertDouble = "impossible";
	}
	doubleStream.str("");
	doubleStream.clear();
}

void	ScalarConverter::convertInvalid(void)
{
	_convertChar = "impossible";
	_convertInt = "impossible";
	_convertFloat = "impossible";
	_convertDouble = "impossible";
}

void	ScalarConverter::convert(std::string &argv)
{	
	if (checkArgsPseudo(argv) == true)
	{
		printValues();
		return ;
	}
	_argvType = checkArgsType(argv);
	switch (_argvType)
	{
		case CHAR_TYPE:
			convertChar(argv);
			break ;
		case INT_TYPE:
			convertInt(argv);
			break ;
		case FLOAT_TYPE:
			convertFloat(argv);
			break ;
		case DOUBLE_TYPE:
			convertDouble(argv);
			break ;
		default :
			convertInvalid();
	}
	printValues();
}


void	ScalarConverter::printValues(void)
{
	if (_convertChar.compare("impossible") && _convertChar.compare("Non displayable"))
		_convertChar = "'" + _convertChar + "'";
	std::cout << "char: " << _convertChar << std::endl;
	std::cout << "int: " << _convertInt << std::endl;
	std::cout << "float: " << _convertFloat << std::endl;
	std::cout << "double: " << _convertDouble << std::endl;
}