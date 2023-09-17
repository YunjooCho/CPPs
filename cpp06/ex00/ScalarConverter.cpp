/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:58:51 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/17 20:49:15 by yunjcho          ###   ########.fr       */
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

	// convertStr >> doubleVal;
	doubleVal = std::strtod(convertStr.str().c_str(), NULL);

	std::cout << "origin : " << doubleVal / 1.0 << std::endl;
	std::cout << "char: \'" << static_cast<char>(doubleVal) << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(doubleVal) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(doubleVal) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(doubleVal) << std::endl;
}

// double	ScalarConverter::getDoubleVal(void)
// {
// 	return (doubleVal);
// }

// std::ostream& operator<<(std::ostream& outputStream, const ScalarConverter& converter)
// {
// 	outputStream << static_cast<double>(converter.doubleVal) / 1.0;
// 	return (outputStream);
// }