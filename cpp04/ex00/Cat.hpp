/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:50:54 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 02:09:48 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& cat);
		Cat&	operator=(const Cat &cat);
		virtual ~Cat();
		virtual void	makeSound(void) const;
};

#endif