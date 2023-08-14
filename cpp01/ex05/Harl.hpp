/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:53:24 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/14 16:16:05 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

enum Code
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};

typedef struct s_codes
{
	std::string	key;
	int			val;
}	t_codes;

class	Harl{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		void(Harl::*funPtr)(void);
		void		complain(std::string level);
		std::string	stringToUppercase(std::string level);
};

#endif