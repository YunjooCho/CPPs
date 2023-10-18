/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:57:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/18 16:07:40 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>
# include <typeinfo>

template <typename T>
T&	plusOne(T& val)
{
	val = val + 1;
	return (val);
}

template <typename T1, typename T2>
void	iter(T1 addr, unsigned long len, T2 func)
{
	for (unsigned long i = 0; i < len; i++)
	{
		addr[i] = func;
		std::cout << "idx : " << i << ", value : " << addr[i] << std::endl;
	}
};

#endif