/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:09:40 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 22:12:20 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character& character);
		Character&	operator=(const Character &character);
		virtual ~Character();
		virtual std::string const	&getName() const;                     // ICharacter 의 추상메서드 구현
		virtual void				equip(AMateria* m);                   // ICharacter 의 추상메서드 구현
		virtual void				unequip(int idx);                     // ICharacter 의 추상메서드 구현
		virtual void				use(int idx, ICharacter& target);     // ICharacter 의 추상메서드 구현
	private:
		std::string	name;
		AMateria	*slot[4];
};

#endif