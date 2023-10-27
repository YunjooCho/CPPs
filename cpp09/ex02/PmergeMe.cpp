/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:09:28 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/28 02:07:49 by yunjcho          ###   ########seoul.kr  */
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
		_conVec.push_back(value);
		idx++;
	}

	//debugging
	for (std::deque<int>::iterator iter = _con.begin(); iter != _con.end(); iter++)
	{
		std::cout << "deq: " << *iter << " ";;
	}
	std::cout << std::endl;

	for (std::vector<int>::iterator iter = _conVec.begin(); iter != _conVec.end(); iter++)
	{
		std::cout << "vec: " << *iter << " ";;
	}
	std::cout << std::endl;
}

void	PmergeMe::createChains(void)
{
	size_t								targetIdx = _con.size() - 2;
	std::deque<int>						_copyCon(_con);
	std::deque<std::pair<int, int> >	_sortChain;

	if (_con.size() % 2 != 0)
		targetIdx -= 1;
	std::deque<int>::iterator iter = _copyCon.begin();
	std::deque<int>::iterator iter2 = ++_copyCon.begin();
	for (size_t i = 0; i <= targetIdx; i += 2)
	{
		if (*iter < *iter2)
			_sortChain.push_back(std::make_pair(*iter2, *iter));
		else if(*iter > *iter2)
			_sortChain.push_back(std::make_pair(*iter, *iter2));
		for (size_t j = 0; j < 2; j++)
		{
			++iter;
			++iter2;
			_copyCon.pop_front();
		}
	}
	
	if (_copyCon.size() > 0)
	{
		_solo = *iter;
	}

	//debugging
	std::cout << "_sortChain size() : " << _sortChain.size() << std::endl;

	std::sort(_sortChain.begin(), _sortChain.end());
	for (std::deque<std::pair<int, int> >::iterator iter = _sortChain.begin(); iter != _sortChain.end(); iter++)
	{
		_mainChain.push_back(iter->first);
		_peChain.push_back(iter->second);
	}

	// debugging
	for (std::deque<int>::iterator iter = _mainChain.begin(); iter != _mainChain.end(); iter++)
	{
		std::cout << "mainChain : " << *iter << std::endl;
	}
	for (std::deque<int>::iterator iter = _peChain.begin(); iter != _peChain.end(); iter++)
	{
		std::cout << "peChain : " << *iter << std::endl;
	}
}

void	PmergeMe::createChainsVec(void)
{	
	size_t								targetIdx = _conVec.size() - 2;
	std::vector<int>					_copyConVec(_conVec);
	std::vector<std::pair<int, int> >	_sortChainVec;

	if (_conVec.size() % 2 != 0)
		targetIdx -= 1;
	std::vector<int>::iterator iter = _copyConVec.begin();
	std::vector<int>::iterator iter2 = ++_copyConVec.begin();
	for (size_t i = 0; i <= targetIdx; i += 2)
	{
		if (*iter < *iter2)
			_sortChainVec.push_back(std::make_pair(*iter2, *iter));
		else if(*iter > *iter2)
			_sortChainVec.push_back(std::make_pair(*iter, *iter2));
		for (size_t j = 0; j < 2; j++)
		{
			++iter;
			++iter2;
			_copyConVec.erase(_copyConVec.begin());
		}
	}
	
	if (_copyConVec.size() > 0)
	{
		_solo = *iter; //TODO - pair가 없는 경우 따로 저장
	}

		//debugging
	std::cout << "_sortChainVec size() : " << _sortChainVec.size() << std::endl;

	std::sort(_sortChainVec.begin(), _sortChainVec.end());
	for (std::vector<std::pair<int, int> >::iterator iter = _sortChainVec.begin(); iter != _sortChainVec.end(); iter++)
	{
		_mainChainVec.push_back(iter->first);
		_peChainVec.push_back(iter->second);
	}

	// debugging
	for (std::vector<int>::iterator iter = _mainChainVec.begin(); iter != _mainChainVec.end(); iter++)
	{
		std::cout << "_mainChainVec : " << *iter << std::endl;
	}
	for (std::vector<int>::iterator iter = _peChainVec.begin(); iter != _peChainVec.end(); iter++)
	{
		std::cout << "_peChainVec : " << *iter << std::endl;
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

std::vector<int> PmergeMe::createOrder(void)
{
	std::vector<int>	_order;
	size_t				targetIdx = -1; // _peChain.size()와 비교하기 위해 size_t
	int					standIdx = 0;   // 야곱스탈 수로 구한 3, 5, 11, 21 등이 _order 안에 저장된 위치(인덱스)
	int					curIdx = 0;     // 야콥스탈 함수를 통해 마지막으로 구한 값이 _order 안에 저장된 위치(인덱스)
	int					distance = 0;   // 야곱스탈 수 끼리의 간격, 1 ~ 3 이면 2, 3 ~ 5 이면 2
	int					n = 3;          // 야콥스탈 수를 구하기 위한 변수(야콥스탈 함수 호출 횟수)

	_order.push_back(1);
	if (_peChain.size() < 2) // pendingElements의 첫번째 값은 무조건 먼저 넣음
	{
		_order.push_back(2); // pendingElements의 첫번째를 제외한 두번째 값의 순서만 정렬 -> 원소개수가 2개만 있는 경우 순서 없이 바로 하드코딩?
	}
	else
	{
		while (true)
		{
			targetIdx = jacobstalNum(n);
			if (targetIdx > _peChain.size())
			{
				_order.push_back(targetIdx);
				break ;
			}
			_order.push_back(targetIdx);
			curIdx = (std::find(_order.begin(), _order.end(), targetIdx) - _order.begin());
			distance = _order[curIdx] - _order[standIdx] - 1;
			standIdx = curIdx;
			for (int i = 1; i < distance + 1; i++)
			{
				_order.push_back(targetIdx - i);
			}
			n++;
		}
	}
	if (_order.size() > _peChain.size())
	{
		int max = *std::max_element(_order.begin(), _order.end());
		_order.erase(std::find(_order.begin(), _order.end(), max));
	}
	*std::max_element(_order.begin(), _order.end()) = _peChain.size();
	return (_order);
}

template <typename Container>
void	PmergeMe::insertionSolo(Container result)
{
	size_t	startIdx = 0;
	size_t	endIdx = 0;

	while (startIdx < endIdx)
	{
		size_t midIdx = (startIdx + endIdx) / 2;
		if (result[midIdx] < _solo)
			startIdx = midIdx + 1;
		else if (result[midIdx] > _solo)
			endIdx = midIdx;
		else
		{
			startIdx = midIdx + 1;
			break ;
		}
	}
	result.insert(result.begin() + startIdx, _solo);
}

void	PmergeMe::mergeInsertionSort(void)
{
	std::deque<int>		result(_mainChain);
	std::vector<int>	_order;
	int					curVal;
	size_t				startIdx = 0;
	size_t				endIdx = 0;

	_order = createOrder();
	//debugging
	for (size_t i = 0; i < _order.size(); i++)
	{
		std::cout << "_order: " << _order[i] << std::endl;
	}


	for (std::vector<int>::iterator iter = _order.begin(); iter != _order.end(); iter++)
	{
		if (*iter == 1)
		{
			result.push_front(_peChain[0]);
			continue ;
		}
		
		startIdx = 0;
		endIdx = std::find(result.begin(), result.end(), _mainChain[*iter - 1]) - result.begin();
		while (startIdx < endIdx)
		{
			curVal = _peChain[*iter - 1];
			size_t midIdx = (startIdx + endIdx) / 2;
			if (result[midIdx] < curVal)
				startIdx = midIdx + 1;
			else if (result[midIdx] > curVal)
				endIdx = midIdx;
			else
			{
				startIdx = midIdx;
				break ;
			}
		}
		result.insert(result.begin() + startIdx, _peChain[*iter - 1]);
	}
	if (_solo != -1)
		insertionSolo(result);
	//debugging
	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << "result : " << result[i] << std::endl;
	}
}

void	PmergeMe::mergeInsertionSortVec(void)
{
	std::vector<int>	resultVec(_mainChainVec);
	std::vector<int>	_orderVec;
	int					curVal;
	size_t				startIdx = 0;
	size_t				endIdx = 0;

	_orderVec = createOrder();
	//debugging
	for (size_t i = 0; i < _orderVec.size(); i++)
	{
		std::cout << "_orderVec: " << _orderVec[i] << std::endl;
	}

	
	for (std::vector<int>::iterator iter = _orderVec.begin(); iter != _orderVec.end(); iter++)
	{
		if (*iter == 1)
		{
			resultVec.insert(resultVec.begin(), _peChainVec[0]);
			continue ;
		}
		
		startIdx = 0;
		endIdx = std::find(resultVec.begin(), resultVec.end(), _mainChainVec[*iter - 1]) - resultVec.begin();
		while (startIdx < endIdx)
		{
			curVal = _peChainVec[*iter - 1];
			size_t midIdx = (startIdx + endIdx) / 2;
			if (resultVec[midIdx] < curVal)
				startIdx = midIdx + 1;
			else if (resultVec[midIdx] > curVal)
				endIdx = midIdx;
			else
			{
				startIdx = midIdx;
				break ;
			}
		}
		resultVec.insert(resultVec.begin() + startIdx, _peChainVec[*iter - 1]);
	}
	if (_solo != -1)
		insertionSolo(resultVec);
	//debugging
	for (size_t i = 0; i < resultVec.size(); i++)
	{
		std::cout << "resultVec : " << resultVec[i] << std::endl;
	}
}

void	PmergeMe::sort(void)
{
	clock_t	startTime;
	clock_t	deqTime;
	clock_t	vecTime;

	
	_solo = -1;
	startTime = clock();
	if (_con.size() == 1 || _conVec.size() == 1)
	{
		deqTime = clock() - startTime;
		vecTime = clock() - startTime;
		printTimes(deqTime, vecTime);
		return ;
	}

	_solo = -1;
	startTime = clock();
	createChains();
	mergeInsertionSort();
	deqTime = clock() - startTime;

	_solo = -1;
	startTime = clock();
	createChainsVec();
	mergeInsertionSortVec();
	vecTime = clock() - startTime;

	printTimes(deqTime, vecTime);
}

void	PmergeMe::printTimes(clock_t deqTime, clock_t vecTime)
{
	std::cout << "Time to process a range of " << _con.size() << " elements with std::deque : " << deqTime * 0.001 << " us" << std::endl;
	std::cout << "Time to process a range of " << _con.size() << " elements with std::list : " << vecTime * 0.001 << " us" << std::endl;
}