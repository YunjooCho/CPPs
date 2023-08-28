/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:15:16 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 00:51:07 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const &type);
		Cure(const Cure& cure);
		Cure&	operator=(const Cure &cure);
		virtual ~Cure();
		virtual AMateria*	clone(void) const;
		virtual void 		use(ICharacter& target);
	private:
		std::string	type;
};

#endif