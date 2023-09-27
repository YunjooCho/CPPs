/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:57:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/27 21:05:48 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T1, typename T2, typename T3>
void	iter(T1& addr, T2& len, T3& func)
{
	//Debugging
	std::cout << "addr : " << addr << std::endl;
	std::cout << "array length : " << len << std::endl;
	std::cout << "function addr : " << func << std::endl;

	T	*arr = new T[len + 1]; //마지막에 0 넣기
	// *a = arr[0];
	for (int i = 0; i < len; i++)
	{
		arr[i] = func;
	}
};

#endif