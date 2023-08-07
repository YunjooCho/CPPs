/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:39:23 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 19:49:59 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string	name;
	public:
		Zombie(std::string name);
		~Zombie();
		void 		announce(void);
}; 

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif