/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:00:09 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/31 15:15:27 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

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
	protected:
		std::string	_type;
};

#endif