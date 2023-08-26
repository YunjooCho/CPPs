/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:23:56 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 02:04:14 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal& animal);
		Animal&	operator=(const Animal &animal);
		virtual ~Animal();
		std::string		getType(void) const;
		virtual void	makeSound(void) const=0;
	protected:
		std::string	type;
};

#endif