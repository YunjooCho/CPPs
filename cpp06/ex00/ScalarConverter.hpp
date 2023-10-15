/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:19:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/15 13:39:59 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <iomanip>
# include <limits>

enum argvType
{
	PSEUDO_INF_M_TYPE,
	PSEUDO_INF_P_TYPE,
	PSEUDO_INF_N_TYPE,
	PSEUDO_NAN_M_TYPE,
	PSEUDO_NAN_P_TYPE,
	PSEUDO_NAN_N_TYPE,
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
		static void			convertInvalid(void);
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