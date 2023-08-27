/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:23:56 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 02:38:35 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal& animal);
		AAnimal&	operator=(const AAnimal &animal);
		virtual ~AAnimal();
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
	protected:
		std::string	type;
};

#endif