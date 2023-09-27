/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:57:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/27 19:45:27 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename A, typename B, typename C>
void	iter(A& a, B& b, C& c)
{
	// T	*arr = new T[b + 1]; //마지막에 0 넣기
	// *a = arr[0];
	// for (int i = 0; i < b; i++)
	// {
	// }
	std::cout << "addr : " << a << std::endl;
	std::cout << "array length : " << b << std::endl;
	std::cout << "function addr : " << c << std::endl;
};

#endif