/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:57:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/17 21:51:05 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
T	plus(T& fir, T& sec)
{
	return (fir + sec);
}

template <typename T1, typename T2, typename T3>
void	iter(T1 addr, T2 len, T3 func)
{
	T1	*arr = new T1[len + 1];
	*arr = addr;
	for (int i = 0; i < static_cast<int>(len); i++)
	{
		arr[i] = &func;
		std::cout << "idx : " << i << ", value : " << *arr[i] << std::endl;
	}
	delete[] arr;
};

#endif