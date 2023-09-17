/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:19:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/17 23:18:04 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <cstdlib> //std::strtod
# include <iomanip> //std::setprecision(1)
# include <limits>  //std::numeric_limits<type>::max(), min()

class ScalarConverter
{
	public:
		static void	convert(std::string &argv);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &form);
		ScalarConverter& operator=(const ScalarConverter &form);
		~ScalarConverter();
};

#endif