/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:09:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/27 01:31:08 by yunjcho          ###   ########seoul.kr  */
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

void	PmergeMe::createChains(void)
{
	size_t			targetIdx = _con.size() - 2;
	std::list<int>	_copyCon(_con);

	if (_con.size() % 2 != 0)
		targetIdx -= 1;
	std::list<int>::iterator iter = _copyCon.begin();
	std::list<int>::iterator iter2 = ++_copyCon.begin();
	for (size_t i = 0; i <= targetIdx; i += 2)
	{
		if (*iter < *iter2)
			_mainChain.push_back(std::make_pair(*iter2, *iter));
		else if(*iter > *iter2)
			_mainChain.push_back(std::make_pair(*iter, *iter2));
		else
			throw std::runtime_error("Error: Duplicate values existed.");
		for (size_t j = 0; j < 2; j++)
		{
			++iter;
			++iter2;
			_copyCon.pop_front();
		}
	}
	
	if (_copyCon.size() > 0)
	{
		while (iter != _copyCon.end())
		{
			_mainChain.push_back(std::make_pair(2147483647, *iter));
			++iter;
		}		
	}

	_mainChain.sort();
	for (std::list<std::pair<int, int> >::iterator iter = _mainChain.begin(); iter != _mainChain.end(); iter++)
	{
		_peChain.push_back(iter->second);
		std::cout << "set key : " << iter->first << ", value : " << iter->second << std::endl;
	}
	for (std::list<int>::iterator iter = _peChain.begin(); iter != _peChain.end(); iter++)
	{
		std::cout << "peChain : " << *iter << std::endl;
	}
}

int		PmergeMe::jacobstalNum(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return jacobstalNum(n - 1) + 2 * jacobstalNum(n - 2);
}

void	PmergeMe::mergeInsertionSort(void)
{
	// int		cnt = 0; // jacobstalNum()을 호출한 횟수
	// size_t	targetIdx = jacobstalNum(cnt);

	std::cout << "jacob0 : " << jacobstalNum(0) << std::endl;
	std::cout << "jacob1 : " << jacobstalNum(1) << std::endl;
	std::cout << "jacob2 : " << jacobstalNum(2) << std::endl;

	std::cout << "jacob3 : " << jacobstalNum(3) << std::endl;
	std::cout << "jacob4 : " << jacobstalNum(4) << std::endl;
	std::cout << "jacob5 : " << jacobstalNum(5) << std::endl;
	std::cout << "jacob6 : " << jacobstalNum(6) << std::endl;
	std::cout << "jacob7 : " << jacobstalNum(7) << std::endl;
}

void	PmergeMe::sort(void)
{
	if (_con.size() == 1)
		return ;
	createChains();
	mergeInsertionSort();
}
