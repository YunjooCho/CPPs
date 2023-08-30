/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:41:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/30 22:05:13 by yunjcho          ###   ########seoul.kr  */
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
	for (int i = 0; i < 4; i++)
	{
		this->skillTree[i] = NULL;
	}
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
	{
		this->slot[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
	{
		this->skillTree[i] = NULL;
	}
}

Character&	Character::operator=(const Character& character)
{
	if (this != & character)
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
		for (int i = 0; i < 4; i++)
		{
			if (this->skillTree[i] != NULL)
			{
				delete this->skillTree[i];
			}
			if (character.skillTree[i] != NULL)
			{
				this->skillTree[i] = character.skillTree[i]->clone();
			}
			else
			{
				this->skillTree[i] = NULL;
			}
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
	for (int i = 0; i < 4; i++)
	{
		if (this->skillTree[i] != NULL)
		{
			delete this->skillTree[i];
			this->skillTree[i] = NULL;
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
	if (m)
		delete m;
}

void	Character::unequip(int idx)
{
	if ((idx >= 0 && idx <= 3) && this->slot[idx] == NULL)
		return ;
	AMateria *tmp = this->slot[idx];
	for (size_t i = 0; i < 4; i++)
	{
		if (this->skillTree[i] == NULL)
		{
			this->skillTree[i] = tmp;
			this->slot[idx] = NULL;
			return ;
		}
	}
	if (tmp)
		delete tmp;
	this->slot[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) && this->slot[idx] != NULL)
		this->slot[idx]->use(target);
}