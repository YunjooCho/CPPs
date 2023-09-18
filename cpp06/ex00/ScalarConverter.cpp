/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:58:51 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/18 21:52:30 by yunjcho          ###   ########.fr       */
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

// void ScalarConverter::convert(std::string &argv)
// {
// 	std::stringstream	convertStr(argv);
// 	double				doubleVal;
// 	const std::string	ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

// 	doubleVal = std::strtod(convertStr.str().c_str(), NULL);

// 	std::cout << "origin : " << doubleVal << std::endl;
// 	std::cout << "str length : " << convertStr.str().length() << std::endl;

// 	//Convert Char
// 	char	charVal = '\0';
// 	if (convertStr.str().find_first_of(ALPHABETS) != std::string::npos)
// 	{
// 		if (convertStr.str().length() == 1)
// 		{
// 			charVal = argv.c_str()[0];
// 		}
// 	}
// 	else
// 	{
// 		charVal = static_cast<char>(doubleVal);
// 	}
// 	if (charVal >= ' ' && charVal <= '~')
// 		std::cout << "char: \'" << charVal << "\'" << std::endl;
// 	else if (convertStr.str().length() == 1 && \
// 		((charVal >= 0 && charVal <= 31) || (charVal == 127)))
// 		std::cout << "char: Non displayable" << std::endl;
// 	else
// 		std::cout << "char: impossible" << std::endl;

// 	//Convert Int
// 	int	intVal = 0;
// 	if (doubleVal > std::numeric_limits<int>::max() \
// 		|| doubleVal < std::numeric_limits<int>::min()) //nan, inf, overflow
// 	{
// 		std::cout << "int: impossible" << std::endl;
// 	}
// 	else if (convertStr.str().find_first_of(ALPHABETS) != std::string::npos)
// 	{
// 		if (convertStr.str().find("f") == (convertStr.str().length() - 1))
// 			std::cout << "int: " << static_cast<int>(doubleVal) << std::endl; // floor()
// 		else
// 		{
// 			if (convertStr.str().length() == 1)
// 			{
// 				intVal = argv.c_str()[0];
// 				std::cout << "int: " << static_cast<int>(intVal) << std::endl; // floor()
// 			}
// 			else if (convertStr.str().length() == 2 && argv.c_str()[0] == '-')
// 			{
// 				intVal = argv.c_str()[1] * -1;
// 				std::cout << "int: " << static_cast<int>(intVal) << std::endl; // floor()
// 			}
// 			else
// 				std::cout << "int: impossible" << std::endl;
// 		}
// 	}
// 	else
// 		std::cout << "int: " << static_cast<int>(doubleVal) << std::endl;

// 	//Convert Float
// 	float	floatVal =  static_cast<float>(doubleVal);
// 	if ((floatVal > std::numeric_limits<float>::max() \
// 		|| floatVal < std::numeric_limits<float>::min()) && floatVal != 0.0)
// 			std::cout << "float: impossible" << std::endl;
// 	else
// 	// << std::scientific
// 		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleVal) << "f" << std::endl;

// 	//Convert Double
// 	if ((doubleVal > std::numeric_limits<double>::max() \
// 		|| doubleVal < std::numeric_limits<double>::min()) && doubleVal != 0.0)
// 			std::cout << "double: impossible" << std::endl;
// 	else
// 	// << std::scientific
// 		std::cout << "double: " << static_cast<double>(doubleVal) << std::endl;
// }

bool	ScalarConverter::checkArgsPseudo(std::string &argv)
{
	std::string	float_pseudo[4] = {"-inff", "+inff", "-nanf", "+nanf"};
	std::string	double_pseudo[4] = {"-inf", "+inf", "-nan", "+nan"};

	for (size_t i = 0; i < float_pseudo->size(); i++)
	{
		if (!argv.compare(float_pseudo[i]))
		{
			_convertChar = "impossible";
			_convertInt = "impossible";
			_convertFloat = float_pseudo[i];
			_convertDouble = double_pseudo[i];
			_argvType = i;
			return (true);
		}
	}
	for (size_t i = 0; i < double_pseudo->size(); i++)
	{
		if (!argv.compare(double_pseudo[i]))
		{
			_convertChar = "impossible";
			_convertInt = "impossible";
			_convertFloat = float_pseudo[i];
			_convertDouble = double_pseudo[i];
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
			if (argv.find_first_of(".") != std::string::npos)
			{
				if (argv.find_last_of("f") == (argv.length() - 1))
					return (FLOAT_TYPE);
				else
					return (DOUBLE_TYPE);
			}
			else
			{
				return (INT_TYPE);
			}
		}
	}
	return (ETC_TYPE);
}

// std::string	ScalarConverter::convertStrCharToChar(std::stringstream &convertStr)
// {
// 	int	charVal = 0;

// 	charVal = convertStr.str().c_str()[0];

// 	std::cout << "charVal : " << charVal << std::endl;

// 	if (charVal >= ' ' && charVal <= '~')
// 	{
// 		std::string	tmp(1, static_cast<char>(convertStr.str().c_str()[0]));
// 		return (tmp);
// 	}
// 	else
// 	{
// 		_argvType = NOND_CHAR_TYPE;
// 		return ("Non displayable");
// 	}
// }

void	ScalarConverter::convertChar(std::stringstream &convertStr)
{
	int	charVal = 0;

	charVal = convertStr.str().c_str()[0];

	//Debugging
	std::cout << "charVal : " << charVal << std::endl;

	if (charVal >= ' ' && charVal <= '~')
	{
		std::string	tmp(1, static_cast<char>(convertStr.str().c_str()[0]));
		_convertChar = tmp;
	}
	else
	{
		_argvType = NOND_CHAR_TYPE;
		_convertChar = "Non displayable";
	}
	_convertInt = std::to_string(charVal);
	_convertFloat = std::to_string(static_cast<float>(charVal));
	_convertDouble = std::to_string(static_cast<double>(charVal));
	// _convertChar = convertStrCharToChar(convertStr);
	// _convertInt = convertStrCharToInt(convertStr);
}

void	ScalarConverter::convertInt(std::stringstream &convertStr)
{
	(void) convertStr;
}

void	ScalarConverter::convertFloat(std::stringstream &convertStr)
{
	(void) convertStr;
}

void	ScalarConverter::convertDouble(std::stringstream &convertStr)
{
	(void) convertStr;
}

void	ScalarConverter::convert(std::string &argv)
{
	std::stringstream	convertStr(argv);

	if (checkArgsPseudo(argv) == true)
	{
		printValues();
		return ;
	}
	_argvType = checkArgsType(argv);
	switch (_argvType)
	{
		case CHAR_TYPE:
			convertChar(convertStr);
			break ;
		case INT_TYPE:
			convertInt(convertStr);
			break ;
		case FLOAT_TYPE:
			convertFloat(convertStr);
			break ;
		case DOUBLE_TYPE:
			convertDouble(convertStr);
	}
	printValues();
}


void	ScalarConverter::printValues(void)
{
	if (_argvType == CHAR_TYPE)
		std::cout << "char: \'" << _convertChar << "\'" << std::endl;
	else
		std::cout << "char: " << _convertChar << std::endl;
	std::cout << "int: " << _convertInt << std::endl;
	std::cout << "float: " << _convertFloat << std::endl;
	std::cout << "double: " << _convertDouble << std::endl;
}