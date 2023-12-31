/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:07:25 by yunjcho           #+#    #+#             */
/*   Updated: 2023/09/01 14:07:13 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob); //anything
		
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);  //anything
		
		delete bob;
		delete me;
		delete src;
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob); //anything
		
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);  //anything
		me->unequip(3);

		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		me->use(0, *bob);
		me->use(1, *bob);

		me->unequip(0);
		me->unequip(1);

		delete bob;
		delete me;
		delete src;
	}
	return 0;
}