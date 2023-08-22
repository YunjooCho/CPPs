/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:51:50 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/22 18:40:59 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define HIT_POINT 10
# define ENERGY_POINT 10
# define ATTACK_DAMAGE 0

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string inputName);
		ClapTrap(const ClapTrap& clapTrap);
		ClapTrap&	operator=(const ClapTrap &clapTrap);
		virtual	~ClapTrap();
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		virtual void	printError(void);
		virtual void	printEnergyPoints(void);
		virtual void	printHitPoints(void);
		virtual void	printAttackDamage(void);
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
};

#endif