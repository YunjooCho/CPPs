/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:00:09 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 22:11:59 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "MateriaSource.hpp"
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(std::string const &type);
		AMateria(const AMateria& aMateria);
		AMateria&	operator=(const AMateria &aMateria);
		virtual ~AMateria();
		std::string const	&getType() const;
		virtual AMateria*	createMateria(std::string const &type);
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
	private:
		std::string	type;
};

#endif