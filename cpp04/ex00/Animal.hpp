/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:23:56 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/25 13:15:19 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& animal);
		Animal&	operator=(const Animal &animal);
		virtual ~Animal();
		std::string		getType(void) const;
		virtual void	makeSound(void) const;
	protected:
		std::string	type;
};

#endif