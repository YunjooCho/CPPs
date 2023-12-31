/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:33:47 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/30 20:42:03 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
  if (ac == 2) {
    std::string argv(av[1]);
    ScalarConverter::convert(argv);
  } else
    std::cout << "Error: Please input argument." << std::endl;
  return (0);
}
