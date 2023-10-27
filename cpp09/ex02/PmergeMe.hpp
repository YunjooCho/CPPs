/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/28 01:34:55 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
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
		void				insertionSolo(Container result);
		void				mergeInsertionSort(void);
		void				mergeInsertionSortVec(void);
		void				sort(void);
		void				printTimes(clock_t deqTime, clock_t vecTime);
	private:
		std::deque<int>		_con;
		std::deque<int>		_mainChain;
		std::deque<int>		_peChain;
		std::vector<int>	_conVec;
		std::vector<int>	_mainChainVec;
		std::vector<int>	_peChainVec;
		int					_solo;
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& instance);
};

#endif


//시간 측정
//컨테이너 추가 - 벡터로 구현
//결과 프린트
//중복 처리