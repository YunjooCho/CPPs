/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:43:16 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 22:00:51 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	std::cout << this->type << " Default constructor called" << std::endl;
	this->name = "ammonymous";
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& materiaSource)
{
	std::cout << this->type << " Copy assignment operator called" << std::endl;
	if (this != &materiaSource)
	{
		this->name = std::string(charcter.getName());
		for (int i = 0; i < 4; i++)
		{
			if (this->slot[i] != NULL)
				delete slot[i];
			if (materiaSource.slot[i] != NULL)
				slot[i] = materiaSource.slot[i]->clone();
			// this->setSlotAtIndex(new AMateria(materiaSource.getSlotIndex(i)), i); 
		}
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource) : IMateriaSource(MateriaSource)
{
	std::cout << this->type << " Copy constructor called" << std::endl;
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	std::cout << this->type << " Destructor called" << std::endl;
}

template <typename AMateria>
virtual void 	learnMateria(AMateria* materiaSource)
{
	for (size_t i = 0; i < manual.size(); i++)
	{
		if (!manual[i])
			manual[i] = materiaSource;
	}
}

template <typename AMateria>
virtual AMateria*	createMateria(std::string const &type)
{
	for (size_t i = 0; i < manual.size(); i++)
	{
		if (manual[i].getType().compare(type.getType()))
			return (manual[i]->clone()); //clone()
	}
	return (0);
}

void	setManualAtIndex(AMateria &newMateria, int idx)
{
	this->manual[idx] = newMateria;
}

AMateria	Character::*&getManualAtIndex(int idx)
{
	return (this->manual[idx]);
}
