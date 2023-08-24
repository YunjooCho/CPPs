/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:38:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 00:33:16 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

enum fragInfo
{
	FRAG_HP = 100,
	FRAG_EP = 100,
	FRAG_AD = 30
};

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string inputName);
		FragTrap(const FragTrap& fragTrap);
		FragTrap&	operator=(const FragTrap &fragTrap);
		virtual ~FragTrap();
		void	highFivesGuys(void);
};

#endif