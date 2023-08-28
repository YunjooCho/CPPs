/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:00:09 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 01:14:03 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "MateriaSource.hpp"
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria& aMateria);
		AMateria&	operator=(const AMateria &aMateria);
		virtual ~AMateria();
		std::string const	&getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
	private:
		std::string	type;
};

#endif