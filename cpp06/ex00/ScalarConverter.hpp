/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:19:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/17 20:44:20 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
	public:
		static void 	convert(std::string &argv);
		// static double	doubleVal;
		// static double	getDoubleVal(void);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &form);
		ScalarConverter& operator=(const ScalarConverter &form);
		~ScalarConverter();
};

// std::ostream& operator<<(std::ostream& outputStream, const ScalarConverter& converter);

#endif