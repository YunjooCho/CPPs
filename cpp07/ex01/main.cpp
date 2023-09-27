/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:33:03 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/27 21:28:07 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	plus(const int fir, const int sec)
{
	return (fir + sec);
}

int	main(void)
{
	int		intArr[5];
	// char	charArr[10];

	::iter(intArr, sizeof(intArr)/sizeof(intArr[0]), ::plus(3, 5));
	return (0);
}

