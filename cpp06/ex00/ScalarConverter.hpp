/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:19:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/30 20:42:12 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

enum argvType {
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

class ScalarConverter {
 public:
  static void convert(std::string &argv);
  static bool checkArgsPseudo(std::string &argv);
  static argvType checkArgsType(std::string &argv);
  static void convertChar(std::string &argv);
  static void convertInt(std::string &argv);
  static void convertFloat(std::string &argv);
  static void convertDouble(std::string &argv);
  static void convertInvalid(void);
  static std::string createChrStr(int intVal);
  static std::string createIntStr(int intVal, double doubleVal);
  static std::string createFloatStr(float floatVal, double doubleVal,
                                    std::string &argv);
  static std::string createDoubleStr(double doubleVal, double checkVal,
                                     std::string &argv);
  static void printValues(void);

 private:
  static std::string _convertChar;
  static std::string _convertInt;
  static std::string _convertFloat;
  static std::string _convertDouble;
  static int _argvType;
  ScalarConverter();
  ScalarConverter(const ScalarConverter &form);
  ScalarConverter &operator=(const ScalarConverter &form);
  ~ScalarConverter();
};

#endif