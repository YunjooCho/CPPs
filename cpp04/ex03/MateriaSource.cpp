/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:43:16 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/31 14:46:55 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		this->manual[i] = NULL;
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& materiaSource)
{
	if (this != &materiaSource)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->manual[i] != NULL)
				delete this->manual[i];
			if (materiaSource.manual[i] != NULL)
			{
				this->manual[i] = materiaSource.manual[i]->clone();
			}
			else
			{
				this->manual[i] = NULL;
			}
		}
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->manual[i] != NULL)
		{
			delete this->manual[i];
		}
	}
}

void 	MateriaSource::learnMateria(AMateria* materiaSource)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->manual[i] == NULL && materiaSource != NULL)
		{
			this->manual[i] = materiaSource;
			break ;
		}
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->manual[i] != NULL)
		{
			if (this->manual[i]->getType().compare(type) == 0)
			{
				
				AMateria *tmp = this->manual[i]->clone();
				return (tmp);
			}
		}
	}
	return (0);
}

