/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/27 21:21:25 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>  //TODO - 추후 불필요한 경우 삭제
# include <deque> //TODO - 추후 불필요한 경우 삭제
# include <vector> //TODO - 추후 불필요한 경우 삭제
# include <sstream>
# include <string>
# include <set>
# include <algorithm>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void				parsing(char **argv);
		void				createChains(void);
		int					jacobstalNum(int n);
		std::vector<int>	createOrder(void);
		void				mergeInsertionSort(void);
		void				sort(void);
	private:
		std::deque<int>	_con;
		std::deque<int>	_mainChain;
		std::deque<int>	_peChain;
		int				_solo;
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& instance);
};

#endif