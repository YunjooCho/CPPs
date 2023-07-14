/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:06:14 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/14 17:22:33 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon &weapon);
		void	attack(void);
		void	setWeapon(Weapon& weapon);
};

#endif