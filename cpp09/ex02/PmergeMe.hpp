/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:02:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/24 22:31:28 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <list>  //TODO - 추후 불필요한 경우 삭제
# include <deque> //TODO - 추후 불필요한 경우 삭제
# include <sstream>
# include <string>

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		void	parsing(char **argv);
		void	sort(void);
	private:
		std::list<int>	_con;
		PmergeMe(const PmergeMe& instance);
		PmergeMe& operator=(const PmergeMe& instance);
};

// template<typename T = int, typename Container> //TODO - 추후 불필요한 경우 삭제
// class PmergeMe
// {
// 	public:
// 		PmergeMe();
// 		~PmergeMe();
// 		Container	parsing(char **argv);
// 		void		sort(Container target);
// 	private:
// 		Container	_con;
// 		PmergeMe(const PmergeMe& instance);
// 		PmergeMe& operator=(const PmergeMe& instance);
// };

#endif