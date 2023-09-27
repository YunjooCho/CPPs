/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:33:03 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/27 21:08:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	plus(int &fir, int &sec)
{
	return (fir + sec);
}

int	main(void)
{
	int		intArr[5];
	char	charArr[10];

	// ::iter(&intArr, intArr.length(), ::plus());
	return (0);
}

