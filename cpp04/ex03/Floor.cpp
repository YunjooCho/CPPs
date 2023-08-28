/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:43:34 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 20:53:10 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor()
{
	std::cout << "Floor Default constructor called" << std::endl;
	for (size_t i = 0; i < trash.size(); i++)
	{
		trash[i] = new AMateria();
	}
}

Floor&	Floor::operator=(const Floor& floor)
{
	std::cout << "Floor Copy assignment operator called" << std::endl;
	if (this != &floor)
	{
		delete [] trash;
		for (int i = 0; i < 10; i++)
		{
			this->trash[i].setMateriaAtTrash(new AMateria(floor.getrMateriaFromTrash(i)));
		}
	}
	return (*this);
}

Floor::Floor(const Floor& floor)
{
	std::cout << "Floor Copy constructor called" << std::endl;
	*this = floor;
}

Floor::~Floor()
{
	
	std::cout << "Floor Destructor called" << std::endl;
	delete[] trash;
}
