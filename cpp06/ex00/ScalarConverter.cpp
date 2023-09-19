/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:58:51 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/20 01:54:27 by yunjcho          ###   ########seoul.kr  */
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
				if (idx == 0 || idx == static_cast<int>(argv.length() - 1))
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
	}
	return (ETC_TYPE);
}

void	ScalarConverter::convertChar(std::string &argv)
{
	std::stringstream	charStream;
	char				charVal = '\0';

	charVal = argv.c_str()[0];
	if  (charVal >= ' ' && charVal <= '~')
	{
		_convertChar = charVal;
	}
	// else
	// {
	// 	_convertChar = "Non displayable";
	// }
	_convertInt = std::to_string(charVal);

	charStream << std::fixed << std::setprecision(1) << static_cast<float>(charVal);
	std::string convertStr = charStream.str();
	_convertFloat = convertStr + "f";
	_convertDouble = convertStr;
}

void	ScalarConverter::convertInt(std::string &argv)
{
	std::stringstream	intStream(argv);
	std::stringstream	intFloatStream;
	int					intVal = 0;
	double				intDoubleVal = 0.0;

	
	intStream >> intVal;
	intDoubleVal = std::strtod(argv.c_str(), NULL);

	std::cout << "intVal : " << intVal << std::endl;

	if (intVal > std::numeric_limits<char>::max() \
		|| intVal < std::numeric_limits<char>::min())
		_convertChar = "impossible";
	else if (intVal >= ' ' && intVal <= '~')
		_convertChar = static_cast<char>(intVal);
	else if (intVal >= 0 && intVal <= 127)
		_convertChar = "Non displayable";
	if (intDoubleVal > std::numeric_limits<int>::max() \
		|| intDoubleVal < std::numeric_limits<int>::min())
	{
		_convertInt = "impossible";
	}
	else
		_convertInt = std::to_string(intVal);
	intFloatStream << std::fixed << std::setprecision(1) << intDoubleVal;
	_convertFloat = intFloatStream.str() + "f";
	_convertDouble = intFloatStream.str();
}

void	ScalarConverter::convertFloat(std::string &argv)
{
	std::stringstream	floatStream;
	float				floatVal = 0.0;
	int					intVal = 0;
	
	floatVal = std::strtof(argv.c_str(), NULL); //부동 소수점 변환이 안되므로 >> 로는 제대로 변환 불가
	intVal = static_cast<int>(floatVal);
	
	//Debugging
	std::cout << "floatVal : " << floatVal << std::endl;
	std::cout << "intVal : " << intVal << std::endl;

	if (intVal > std::numeric_limits<char>::max() \
		|| intVal < std::numeric_limits<char>::min())
		_convertChar = "impossible";
	else if (intVal >= ' ' && intVal <= '~')
		_convertChar = static_cast<char>(intVal);
	else if (intVal >= 0 && intVal <= 127)
		_convertChar = "Non displayable";
	if (intVal > std::numeric_limits<int>::max() \
		|| intVal < std::numeric_limits<int>::min())
	{
		_convertInt = "impossible";
	}
	else
	{
		_convertInt = std::to_string(static_cast<int>(intVal));
	}
	floatStream << std::fixed << std::setprecision(1) << floatVal;
	std::string	convertStr = floatStream.str();
	_convertFloat = convertStr + "f";
	_convertDouble = convertStr;
}

void	ScalarConverter::convertDouble(std::string &argv)
{
	std::stringstream	doubleStream;
	double				doubleVal = 0.0;
	int					intVal = 0;

	doubleVal = std::strtod(argv.c_str(), NULL); //부동 소수점 변환이 안되므로 >> 로는 제대로 변환 불가
	intVal = static_cast<int>(doubleVal);

	//Debugging
	std::cout << "doubleVal : " << doubleVal << std::endl;
	std::cout << "intVal : " << intVal << std::endl;
	
	if ((intVal > std::numeric_limits<char>::max() \
		|| intVal < std::numeric_limits<char>::min()) \
		|| argv.find("e") != std::string::npos)
		_convertChar = "impossible";
	else if (intVal >= ' ' && intVal <= '~')
		_convertChar = static_cast<char>(intVal);
	else if (intVal >= 0 && intVal <= 127)
		_convertChar = "Non displayable";
	if ((doubleVal > std::numeric_limits<int>::max() \
		|| doubleVal < std::numeric_limits<int>::min()) \
		|| argv.find("e") != std::string::npos)
	{
		_convertInt = "impossible";
	}
	else
	{
		_convertInt = std::to_string(static_cast<int>(intVal));
	}
	doubleStream << std::fixed << std::setprecision(1) << doubleVal;
	std::string	convertStr = doubleStream.str();
	if ((doubleVal > std::numeric_limits<float>::max() \
		|| doubleVal < std::numeric_limits<float>::min()) \
		&& doubleVal != 0.0)
			_convertFloat  = "impossible";
	else
		_convertFloat = convertStr + "f";
	_convertDouble = convertStr;
}

void	ScalarConverter::convertInvalid(std::string &argv)
{
	//Debugging
	std::cout << argv << std::endl;

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
			convertInvalid(argv);
	}
	printValues();
}


void	ScalarConverter::printValues(void)
{
	//Debugging
	std::cout << "argument type : " << _argvType << std::endl;
	
	std::cout << "char: " << _convertChar << std::endl;
	std::cout << "int: " << _convertInt << std::endl;
	std::cout << "float: " << _convertFloat << std::endl;
	std::cout << "double: " << _convertDouble << std::endl;
}