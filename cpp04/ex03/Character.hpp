/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:09:40 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/30 22:15:49 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MateriaSource.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character& character);
		Character&	operator=(const Character &character);
		virtual ~Character();
		virtual std::string const	&getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
	private:
		std::string		name;
		AMateria		*slot[4];
		AMateria		*skillTree[4];
};

#endif