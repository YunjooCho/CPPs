/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/27 01:25:05 by yunjcho          ###   ########seoul.kr  */
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
		void	createChains(void);
		int		jacobstalNum(int n);
		void	mergeInsertionSort(void);
		void	sort(void);
	private:
		std::list<int>					_con;
		std::list<std::pair<int, int> > _mainChain;
		std::list<int>					_peChain;
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& instance);
};

#endif