/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/29 13:19:35 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <deque>
# include <vector>
# include <sstream>
# include <string>
# include <set>
# include <algorithm>
# include <ctime>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void				parsing(char **argv);
		void				sort(void);
		std::vector<int>	createOrder(void);
		int					jacobstalNum(int n);
		void				createChains(void);
		void				mergeSortMainChain(std::deque<std::pair<int, int> >&_sortChain, size_t startIdx, size_t endIdx);
		void				merge(std::deque<std::pair<int, int> >& _sortChain, size_t startIdx, size_t midIdx, size_t endIdx);
		void				mergeInsertionSort(void);
		void				insertionSolo(std::deque<int>& result);
		void				createChainsVec(void);
		void				mergeSortMainChainVec(std::vector<std::pair<int, int> >&_sortChainVec, size_t startIdx, size_t endIdx);
		void				mergeVec(std::vector<std::pair<int, int> >& _sortChainVec, size_t startIdx, size_t midIdx, size_t endIdx);
		void				mergeInsertionSortVec(void);
		void				insertionSoloVec(std::vector<int>& result);
		void				printArgs(void);
		void				printTimes(clock_t deqTime, clock_t vecTime);
	private:
		std::deque<int>		_con;
		std::deque<int>		_mainChain;
		std::deque<int>		_peChain;
		std::deque<int>		_result;
		std::vector<int>	_conVec;
		std::vector<int>	_mainChainVec;
		std::vector<int>	_peChainVec;
		std::vector<int>	_resultVec;
		int					_solo;
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& instance);
};

#endif
