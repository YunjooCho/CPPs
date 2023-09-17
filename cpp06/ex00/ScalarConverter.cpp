/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:58:51 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/17 23:20:40 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
//static Class는 생성자와 소멸자를 정의 할 수 없음
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &form) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &form) {}
ScalarConverter::~ScalarConverter() {}
*/

void ScalarConverter::convert(std::string &argv)
{
	std::stringstream	convertStr(argv);
	double				doubleVal;
	const std::string	ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	doubleVal = std::strtod(convertStr.str().c_str(), NULL);

	std::cout << "origin : " << doubleVal << std::endl;

	//Convert Char
	char	charVal = static_cast<char>(doubleVal);
	if (charVal >= ' ' && charVal <= '~')
		std::cout << "char: \'" << charVal << "\'" << std::endl;
	else if (convertStr.str().size() == 1)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	//Convert Int
	if (convertStr.str().find_first_of(ALPHABETS) != std::string::npos \
		|| doubleVal > std::numeric_limits<int>::max() \
		|| doubleVal < std::numeric_limits<int>::min()) //nan, inf, overflow
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(doubleVal) << std::endl;

	//Convert Float
	float	floatVal =  static_cast<float>(doubleVal);
	if ((floatVal > std::numeric_limits<float>::max() \
		|| floatVal < std::numeric_limits<float>::min()) && floatVal != 0.0)
			std::cout << "float: impossible" << std::endl;
	else
	// << std::scientific
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleVal) << "f" << std::endl;

	//Convert Double
	if ((doubleVal > std::numeric_limits<double>::max() \
		|| doubleVal < std::numeric_limits<double>::min()) && doubleVal != 0.0)
			std::cout << "double: impossible" << std::endl;
	else
	// << std::scientific
		std::cout << "double: " << static_cast<double>(doubleVal) << std::endl;
}