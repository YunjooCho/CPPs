/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:37:52 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/24 17:50:40 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include "iostream"

// void	_leaks()
// {
// 	system("leaks serializer");
// }

int	main(void)
{
	Data		data;
	uintptr_t	serialVal;
	Data		*deserialVal;
	

	// atexit(_leaks);
	data.val = -10;
	serialVal = Serializer::serialize(&data);
	deserialVal = Serializer::deserialize(serialVal);

	std::cout << "Input value is : " << data.val << std::endl;
	std::cout << "deserialVal's value : " << deserialVal->val << std::endl;
	if (deserialVal == &data)
	{
		std::cout << "SUCCESS !" << std::endl;
	}
	else
	{
		std::cout << "FAILURE !" << std::endl;
	}

	return (0);
}