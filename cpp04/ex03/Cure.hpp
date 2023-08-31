/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:15:16 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/31 15:14:33 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

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
};

#endif