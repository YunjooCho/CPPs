/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:56:31 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/06 18:10:07 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <list>
# include <deque>
# include <exception>
# include <iostream>

template<typename T>
typename T::iterator easyfind(T& fir, int sec)
{
	typename T::iterator iter = std::find(fir.begin(), fir.end(), sec);

	if (iter != fir.end())
		return (iter);
	else
		throw std::runtime_error("[Exception] Not found Value");
}

#endif