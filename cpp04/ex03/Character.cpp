/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:41:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 00:40:22 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter()
{
	this->name = "ammonymous";
	std::cout << "Character "<< this->name << " Default constructor called" << std::endl;
	//TODO - for문으로 slot NULL 대입
}

Character::Character(std::string name) : ICharacter()
{
	this->name = "ammonymous";
	std::cout << "Character "<< this->name << " Default constructor called" << std::endl;
	//TODO - for문으로 slot NULL 대입
}

Character&	Character::operator=(const Character& character)
{
	std::cout << "Character Copy assignment operator called" << std::endl;
	if (this != &character)
	{
		this->name = std::string(character.getName());
		for (int i = 0; i < 4; i++)
		{
			if (this->slot[i] != NULL)
			{
				delete this->slot[i];
				this->slot[i] = NULL;
			}
			if (character.slot[i] != NULL)
				slot[i] = character.slot[i]->clone();
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

std::string const	Character::&getName() const
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

void	equip(AMateria* m)
{
	for (size_t i = 0; i < this->slot.size(); i++)
	{
		if (this->slot[i] == NULL)
			this->slot[i] = m;
	}
	// delete m;
}

void	unequip(int idx)
{
	if (this->slot[idx] == NULL)
		return ;
	this->slot[idx] = NULL;
}

virtual void	use(int idx, ICharacter& target)
{
	this->slot[idx].use(target);
}