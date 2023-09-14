/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:19:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/14 18:38:14 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	public:
		static void convert(std::string &argv);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &form);
		ScalarConverter& operator=(const ScalarConverter &form);
		~ScalarConverter();
};

#endif