/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:57:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/18 15:00:34 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T>
T	plus(T& val)
{
	val += 1;
	return (val);
}

template <typename T1>
void	iter(T1 addr, unsigned long len, T1 (*const funcPtr)(T1))
{
	for (unsigned long i = 0; i < len; i++)
	{
		addr[i] = funcPtr(T1);
		std::cout << "idx : " << i << ", value : " << addr[i] << std::endl;
	}
};

#endif