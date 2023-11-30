/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:37:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/30 20:41:43 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include "iostream"

int main(void) {
  Data data;
  uintptr_t serialVal;
  Data *deserialVal;

  data.val = -10;
  serialVal = Serializer::serialize(&data);
  deserialVal = Serializer::deserialize(serialVal);

  std::cout << serialVal << std::endl;
  std::cout << deserialVal << std::endl;

  std::cout << "Input value is : " << data.val << std::endl;
  std::cout << "deserialVal's value : " << deserialVal->val << std::endl;
  if (deserialVal == &data) {
    std::cout << "SUCCESS !" << std::endl;
  } else {
    std::cout << "FAILURE !" << std::endl;
  }

  return (0);
}