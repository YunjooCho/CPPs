/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/26 21:44:00 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>  //TODO - 추후 불필요한 경우 삭제
# include <deque> //TODO - 추후 불필요한 경우 삭제
# include <sstream>
# include <string>
# include <set>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void	parsing(char **argv);
		void	pairSort(void);
		// void	mainChainSort(void);
		// void	mergeInsertionSort(void);
		void	sort(void);
		// class Pair
		// {
		// 	public:
		// 		int	_x;
		// 		int	_y;
		// 		Pair(int x, int y);
		// 		~Pair();
		// 	private:
		// 		Pair();
		// 		Pair(const Pair& pair);
		// 		Pair& operator=(const Pair& pair);
		// 		// bool  operator<(const Pair& pair) const;
		// };
	private:
		// typedef std::pair<int, int> 	_setPairs;
		std::set<std::pair<int, int> >	_mainChain;
		std::list<int>					_con;
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& instance);
};

#endif