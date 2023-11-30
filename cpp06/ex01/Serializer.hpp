/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:26:43 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/30 20:41:58 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

#include "Data.hpp"

class Serializer {
 public:
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

 private:
  Serializer();
  Serializer(const Serializer& form);
  Serializer& operator=(const Serializer& form);
  ~Serializer();
};

#endif