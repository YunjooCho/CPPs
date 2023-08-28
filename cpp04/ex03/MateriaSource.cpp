/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:43:16 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 02:02:36 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
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
				delete manual[i];
			if (materiaSource.manual[i] != NULL)
				manual[i] = materiaSource.manual[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& materiaSource) : IMateriaSource(materiaSource)
{
	*this = materiaSource;
}

MateriaSource::~MateriaSource()
{
}

void 	MateriaSource::learnMateria(AMateria* materiaSource)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!manual[i])
			manual[i] = materiaSource;
	}
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->manual[i] != NULL)
		{
			if (this->manual[i]->getType().compare(type))
				return (manual[i]->clone());
		}
	}
	return (0);
}

