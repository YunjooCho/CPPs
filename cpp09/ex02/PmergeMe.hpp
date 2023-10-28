/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/28 21:47:03 by yunjcho          ###   ########.fr       */
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
		void				createChains(void);
		void				createChainsVec(void);
		int					jacobstalNum(int n);
		std::vector<int>	createOrder(void);
		template <typename Container>
		void				insertionSolo(Container& result);
		void				merge(std::deque<std::pair<int, int> >& _sortChain, int startIdx, int endIdx, int depth);
		void				mergeSortMainChain(std::deque<std::pair<int, int> >&_sortChain, int startIdx, int endIdx, int depth);
		void				mergeInsertionSort(void);
		void				mergeInsertionSortVec(void);
		void				sort(void);
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
