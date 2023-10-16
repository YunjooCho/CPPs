/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:58:51 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/16 21:11:55 by yunjcho          ###   ########.fr       */
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
				if (idx == 0 || idx == static_cast<int>(argv.length() - 1) \
					|| argv.find(".", idx + 1) != std::string::npos)
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

std::string	ScalarConverter::createChrStr(int intVal)
{
	if (intVal > std::numeric_limits<char>::max() \
		|| intVal < std::numeric_limits<char>::min())
		_convertChar = "impossible";
	else if (intVal >= ' ' && intVal <= '~')
		_convertChar = static_cast<char>(intVal);
	else
		_convertChar = "Non displayable";
	return (_convertChar);
}

std::string ScalarConverter::createIntStr(int intVal, double checkVal)
{
	if (checkVal > std::numeric_limits<int>::max() \
		|| checkVal < std::numeric_limits<int>::min())
		_convertInt = "impossible";
	else
		_convertInt = std::to_string(static_cast<int>(intVal));
	return (_convertInt);
}

std::string	ScalarConverter::createFloatStr(float floatVal, double checkVal, std::string &argv)
{
	std::stringstream	floatStream;

	if ((_argvType == FLOAT_TYPE || _argvType == DOUBLE_TYPE) \
		&&((argv.find("e") != std::string::npos \
		|| argv.substr(argv.find("."), argv.length()).length() > 2)))
		floatStream << floatVal;
	else
		floatStream << std::fixed << std::setprecision(1) << floatVal;
	std::string convertStr = floatStream.str();
	if ((checkVal > std::numeric_limits<float>::max() \
		|| checkVal < std::numeric_limits<float>::min()) \
		&& checkVal != 0.0)
		_convertFloat = "impossible";
	else if (checkVal == 0.0)
	{
		_convertFloat = "0.0f";
	}
	else
	{
		_convertFloat = convertStr + "f";
	}
	floatStream.str("");
	floatStream.clear();
	return (_convertFloat);
}

std::string	ScalarConverter::createDoubleStr(double doubleVal, double checkVal, std::string &argv)
{
	std::stringstream	doubleStream;

	if ((_argvType == FLOAT_TYPE || _argvType == DOUBLE_TYPE) \
		&& (argv.find("e") != std::string::npos \
		|| argv.substr(argv.find("."), argv.length()).length() > 2))
		doubleStream << doubleVal;
	else
		doubleStream << std::fixed << std::setprecision(1) << doubleVal;
	std::string convertStr = doubleStream.str();
	if ( _argvType == DOUBLE_TYPE && convertStr.compare(argv.substr(0, convertStr.length()))\
		&& checkVal != 0.0)
		_convertDouble = "impossible";
	else if (checkVal == 0.0)
		_convertDouble = "0.0";
	else
		_convertDouble = convertStr;
	doubleStream.str("");
	doubleStream.clear();
	return (_convertDouble);
}

void	ScalarConverter::convertChar(std::string &argv)
{
	std::stringstream	charStream;
	int					intVal = 0;

	if (argv.length() == 2 && argv.c_str()[0] == '-')
	{
		intVal = static_cast<int>(argv.c_str()[1]);
		intVal *= -1;
	}
	else
	{
		intVal = static_cast<int>(argv.c_str()[0]);
	}

	createChrStr(intVal);
	_convertInt = std::to_string(intVal);

	charStream << std::fixed << std::setprecision(1) << static_cast<float>(intVal);
	std::string convertStr = charStream.str();
	_convertFloat = convertStr + "f";
	charStream.str("");
	charStream.clear();

	charStream << std::fixed << std::setprecision(1) << static_cast<double>(intVal);
	convertStr = charStream.str();
	_convertDouble = convertStr;
}

void	ScalarConverter::convertInt(std::string &argv)
{
	std::stringstream	convertIntStream(argv);
	double				checkVal = 0;
	int					intVal = 0;
	float				floatVal = 0.0;
	double				doubleVal = 0.0;

	checkVal = std::strtod(argv.c_str(), NULL);
	convertIntStream >> intVal;
	floatVal = static_cast<float>(intVal);
	doubleVal = static_cast<double>(intVal);

	if (checkVal > std::numeric_limits<int>::max() \
		|| checkVal < std::numeric_limits<int>::min())
	{
		convertInvalid();
		return ;
	}

	createChrStr(intVal);
	createIntStr(intVal, checkVal);
	createFloatStr(floatVal, checkVal, argv);
	createDoubleStr(doubleVal, checkVal, argv);
}

void	ScalarConverter::convertFloat(std::string &argv)
{
	double				checkVal = 0.0;
	int					intVal = 0;
	float				floatVal = 0.0;
	double 				doubleVal = 0.0;

	checkVal = std::strtod(argv.c_str(), NULL);
	floatVal = std::strtof(argv.c_str(), NULL);
	intVal = static_cast<int>(floatVal);
	doubleVal = static_cast<double>(floatVal);

	if ((checkVal > std::numeric_limits<float>::max() \
		|| checkVal < std::numeric_limits<float>::min()) \
		&& checkVal != 0.0)
	{
		convertInvalid();
		return ;
	}

	createChrStr(intVal);
	createIntStr(intVal, checkVal);
	createFloatStr(floatVal, checkVal, argv);
	createDoubleStr(doubleVal, checkVal, argv);
}

void	ScalarConverter::convertDouble(std::string &argv)
{
	int					intVal = 0;
	float				floatVal = 0.0;
	double 				doubleVal = 0.0;

	
	doubleVal = std::strtod(argv.c_str(), NULL);
	intVal = static_cast<int>(doubleVal);
	floatVal = static_cast<float>(doubleVal);

	createChrStr(intVal);
	createIntStr(intVal, doubleVal);
	createFloatStr(floatVal, doubleVal, argv);
	createDoubleStr(doubleVal, doubleVal, argv);
	if (!_convertDouble.compare("impossible"))
		convertInvalid();
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