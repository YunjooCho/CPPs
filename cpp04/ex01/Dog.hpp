/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:40:07 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/26 01:05:21 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& dog);
		Dog&	operator=(const Dog &dog);
		virtual ~Dog();
		virtual void	makeSound(void) const;
		Brain	*getBrain(void) const;
		void	setBrain(Brain* brain);
	private:
		Brain	*brain;
};

#endif