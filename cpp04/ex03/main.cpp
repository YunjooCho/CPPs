/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:07:25 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 01:57:38 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		AMateria* tmp2;

		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp2 = src->createMateria("cure");
		me->equip(tmp2);
		ICharacter* bob = new Character("bob");
		
		me->use(0, * bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl;
		std::cout << "[constructor]" << std::endl;
		std::cout << "-----------------------" << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		std::cout << std::endl;

		std::cout << "[createMateria]" << std::endl;
		std::cout << "-----------------------" << std::endl;

		AMateria *tmp;
		AMateria *tmp1;
		AMateria *tmp2;
		AMateria *tmp3;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp1 = src->createMateria("cure");
		me->equip(tmp1);
		tmp2 = src->createMateria("attack");
		me->equip(tmp2);
		std::cout << std::endl;

		std::cout << "[use]" << std::endl;
		std::cout << "-----------------------" << std::endl;
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;
		me->use(2, *bob);
		me->use(-4, *bob);
		me->use(18, *bob);
		std::cout << std::endl;

		std::cout << "[deep copy]" << std::endl;
		std::cout << "-----------------------" << std::endl;
		Character *charles = new Character("Charles");
		tmp2 = src->createMateria("cure");
		charles->equip(tmp2);
		tmp3 = src->createMateria("ice");
		charles->equip(tmp3);
		charles->unequip(0);
		charles->unequip(1);
		tmp = src->createMateria("earth");
		charles->equip(tmp);
		std::cout << std::endl;

		std::cout << "[unequip]" << std::endl;
		std::cout << "-----------------------" << std::endl;
		me->unequip(-1);
		me->unequip(18);
		me->unequip(3);
		std::cout << std::endl;
		me->use(1, *charles);
		me->unequip(1);
		me->use(1, *charles);
		std::cout << std::endl;

		std::cout << "[delete]" << std::endl;
		std::cout << "-----------------------" << std::endl;
		delete bob;
		delete me;
		delete src;
		delete charles;
		delete tmp1;
		delete tmp2;
		delete tmp3;
		std::cout << std::endl;
	}
	return 0;
}