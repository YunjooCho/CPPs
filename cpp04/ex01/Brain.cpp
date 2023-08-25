/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:46:15 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/26 00:27:10 by yunjcho          ###   ########seoul.kr  */
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
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.getIdea(i);
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
	char tmp[idea.size()];

	for (size_t i = 0; i < idea.size(); i++)
	{
		tmp[i] = idea[i];
	}
	this->ideas[idx] = tmp; //std::string(tmp)
}