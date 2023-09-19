/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:19:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/19 18:33:39 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib> //std::strtod
# include <iomanip> //std::setprecision(1)
# include <limits>  //std::numeric_limits<type>::max(), min()

enum argvType
{
	PSEUDO_INF_M_TYPE,
	PSEUDO_INF_P_TYPE,
	PSEUDO_NAN_M_TYPE,
	PSEUDO_NAN_P_TYPE,
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	ETC_TYPE
};

class ScalarConverter
{
	public:
		static void			convert(std::string &argv);
		static bool			checkArgsPseudo(std::string &argv);
		static int			checkArgsType(std::string &argv);
		static void			convertChar(std::string &argv);
		static void			convertInt(std::string &argv);
		static void			convertFloat(std::string &argv);
		static void			convertDouble(std::string &argv);
		// static std::string	convertStrCharToChar(std::stringstream &convertStr);
		static void			printValues(void);
	private:
		static std::string	_convertChar;
		static std::string	_convertInt;
		static std::string	_convertFloat;
		static std::string	_convertDouble;
		static int			_argvType;
		ScalarConverter();
		ScalarConverter(const ScalarConverter &form);
		ScalarConverter& operator=(const ScalarConverter &form);
		~ScalarConverter();
};

#endif