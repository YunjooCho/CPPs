/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:38:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/22 19:59:01 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string inputName);
		FragTrap(const FragTrap& fragTrap);
		FragTrap&	operator=(const FragTrap &fragTrap);
		~FragTrap();
		void	printError(void);
		void	printEnergyPoints(void);
		void	printHitPoints(void);
		void	printAttackDamage(void);
		void	highFivesGuys(void);
};

#endif