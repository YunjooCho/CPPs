/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:09:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/24 22:55:01 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

//private
PmergeMe& PmergeMe::operator=(const PmergeMe& instance) 
{
	if (this != &instance)
	{
		_con = instance._con;
	}
	return (*this);
}

//private
PmergeMe::PmergeMe(const PmergeMe& instance) 
{
	*this = instance;
}

void	PmergeMe::parsing(char **argv)
{
	const std::string	NUMBERS = "0123456789";
	std::stringstream	convert;
	int					value;
	size_t 				idx = 1;

	while (argv[idx])
	{
		convert.str("");
		convert.clear();
		convert << argv[idx];
		if (argv[idx][0] == '-' || convert.str().find_first_of(NUMBERS) == std::string::npos)
			throw std::runtime_error("Error: not a positive number. => " + convert.str());
		convert >> value;

		//debugging
		// std::cout << "argv[idx] : " << argv[idx] << std::endl;
		// std::cout << "convert.str() : " << convert.str() << std::endl;
		// std::cout << "value : " << value << std::endl;

		_con.push_back(value);
		idx++;
	}

	//debugging
	for (std::list<int>::iterator iter = _con.begin(); iter != _con.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
}

void	PmergeMe::sort(void)
{
	
}

// Container	PmergeMe::parsing(char **argv) 
// {}

// void	PmergeMe::sort(Container target)
// {
	
// }