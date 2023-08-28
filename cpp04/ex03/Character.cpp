/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:41:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 22:03:32 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter()
{
	this->name = "ammonymous";
	std::cout << "Character "<< this->name << " Default constructor called" << std::endl;
}

Character::Character(std::string name) : ICharacter(name)
{
	this->name = "ammonymous";
	std::cout << "Character "<< this->name << " Default constructor called" << std::endl;
}

Character&	Character::operator=(const Character& character)
{
	std::cout << "Character Copy assignment operator called" << std::endl;
	if (this != &character)
	{
		this->name = std::string(charcter.getName());
		for (int i = 0; i < 4; i++)
		{
			if (this->slot[i] != NULL)
			{
				delete this->slot[i];
				this->slot[i] = NULL;
			}
			if (character.slot[i] != NULL)
				slot[i] = character.slot[i]->clone();
			// this->setSlotAtIndex(new AMateria(character.getSlotIndex(i)), i);
		}
	}
	return (*this);
}

Character::Character(const Character& character) : ICharacter(character)
{
	std::cout << "Character Copy constructor called" << std::endl;
	*this = character;
}

Character::~Character()
{
	
	std::cout << "Character " << this->name << " Destructor called" << std::endl;
	delete[] slot;
}

virtual std::string const	Character::&getName() const
{
	return (this->name);
}

void	setSlotAtIndex(AMateria &newMateria, int idx)
{
	this->slot[idx] = newMateria;
}

AMateria	Character::*&getSlotAtIndex(int idx)
{
	return (this->slot[idx]);
}

virtual void	equip(AMateria* m)
{
	for (size_t i = 0; i < this->slot.size(); i++)
	{
		if (this->slot[i] == NULL)
			this->slot[i] = m;
	}
	// delete m;
}

virtual void	unequip(int idx)
{
	if (this->slot[idx] == NULL)
		return ;
	this->slot[idx] = NULL;
}

virtual void	use(int idx, ICharacter& target)
{
	this->slot[idx].use(target);
}