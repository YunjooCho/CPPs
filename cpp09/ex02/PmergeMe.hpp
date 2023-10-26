/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/26 22:15:35 by yunjcho          ###   ########.fr       */
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
		void	createMainchain(void);
		// void	mergeInsertionSort(void);
		void	sort(void);
	private:
		// std::set<std::pair<int, int> >	_mainChain;
		std::list<std::pair<int, int> > _mainChain;
		std::list<int>					_con;
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& instance);
};

#endif