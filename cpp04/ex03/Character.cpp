/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:41:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 03:26:04 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	this->name = "ammonymous";
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
	}
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
	}
}

Character&	Character::operator=(const Character& character)
{
	this->name = std::string(character.getName());
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] != NULL)
		{
			delete this->slot[i];
		}
		if (character.slot[i] != NULL)
		{
			this->slot[i] = character.slot[i]->clone();
		}
		else
		{
			this->slot[i] = NULL;
		}
	}
	return (*this);
}

Character::Character(const Character& character)
{
	*this = character;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->slot[i] != NULL)
		{
			delete this->slot[i];
			this->slot[i] = NULL;
		}
	}
}

std::string const	&Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->slot[i] == NULL)
		{
			this->slot[i] = m;
			return ;
		}
	}
	delete m;
}

void	Character::unequip(int idx)
{
	if ((idx >= 0 && idx <= 3) && this->slot[idx] == NULL)
		return ;
	this->slot[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) && this->slot[idx] != NULL)
		this->slot[idx]->use(target);
}