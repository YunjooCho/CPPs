/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:04:53 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 00:23:33 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string inputName);
		DiamondTrap(const DiamondTrap& diamondTrap);
		DiamondTrap&	operator=(const DiamondTrap &diamondTrap);
		virtual ~DiamondTrap();
		virtual void	attack(const std::string& target);
		void	whoAmI(void);
};

#endif