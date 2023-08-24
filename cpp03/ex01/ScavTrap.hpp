/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:51:50 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/24 23:11:15 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

enum scavInfo
{
	SCAV_HP = 100,
	SCAV_EP = 50,
	SCAV_AD = 20
};

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string inputName);
		ScavTrap(const ScavTrap& scavTrap);
		ScavTrap&	operator=(const ScavTrap &scavTrap);
		virtual ~ScavTrap();
		virtual void	attack(const std::string& target);
		void			guardGate(void);
		// void			beRepaired(unsigned int amount); // 결과값 테스트용
};

#endif