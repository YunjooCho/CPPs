/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:32:43 by yunjcho           #+#    #+#             */
/*   Updated: 2023/11/30 20:41:50 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/*
//static Class는 생성자와 소멸자를 정의 할 수 없음
Serializer::Serializer() {}
Serializer::Serializer(const Serializer &form) {}
Serializer& Serializer::operator=(const Serializer &form) {}
Serializer::~Serializer() {}
*/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}