/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:09:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/26 18:19:28 by yunjcho          ###   ########.fr       */
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
	long				value;
	size_t 				idx = 1;

	while (argv[idx])
	{
		convert.str("");
		convert.clear();
		convert << argv[idx];
		if (argv[idx][0] == '-' \
			|| convert.str().find_first_not_of(NUMBERS) != std::string::npos)
			throw std::runtime_error("Error"); 

		convert >> value;
		if (value > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: too large a number." + std::to_string(value)); 
		_con.push_back(value);
		idx++;
	}

	//debugging
	for (std::list<int>::iterator iter = _con.begin(); iter != _con.end(); iter++)
	{
		std::cout << *iter << " ";;
	}
	std::cout << std::endl;

}

void	PmergeMe::pairSort(void)
{
	size_t	targetIdx = _con.size() - 2;

	if (_con.size() % 2 != 0)
		targetIdx -= 1;

	std::list<int>::iterator iter = _con.begin();
	std::list<int>::iterator iter2 = ++_con.begin();
	for (size_t i = 0; i <= targetIdx; i += 2)
	{
		if (*iter < *iter2)
		{
			_sortCon.push_back(*iter2);
			_sortCon.push_back(*iter);
		}
		else
		{
			_sortCon.push_back(*iter);
			_sortCon.push_back(*iter2);
		}
		for (size_t j = 0; j < 2; j++)
		{
			++iter;
			++iter2;
			_con.pop_front();
		}
	}
	
	if (_con.size() > 0)
	{
		while (iter != _con.end())
		{
			//debugging
			// std::cout << "!iter : " << *iter << std::endl;
			_sortCon.push_back(*iter);
			++iter;
		}		
	}

	//debugging
	for (std::list<int>::iterator iter = _sortCon.begin(); iter != _sortCon.end(); iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::mainChainSort(void)
{
	size_t		targetIdx = _con.size() - 2;
	int			val1 = -1;
	int 		val2 = -1;
	std::list<int> tmp;

	(void) val1;
	(void) val2;
	(void) tmp;
	if (_sortCon.size() % 2 != 0)
		targetIdx -= 1;
}

void	PmergeMe::sort(void)
{
	if (_con.size() == 1)
		return ;
	pairSort();
	mainChainSort();
	mergeInsertionSort();
}
