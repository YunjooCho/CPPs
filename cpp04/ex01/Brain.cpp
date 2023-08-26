/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:46:15 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 01:42:26 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain &brain)
{
	std::cout << "Brain Copy assignment operator called" << std::endl;
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
		{
			this->setIdea(brain.getIdea(i), i);
		}
	}
	return (*this);
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = brain;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

std::string	Brain::getIdea(int idx) const
{
	return (this->ideas[idx]);
}

void	Brain::setIdea(std::string idea, int idx)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[idx] = std::string(idea);
	}
}