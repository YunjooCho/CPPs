/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:04:49 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/29 15:33:24 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>

class RPN
{
	public:
		RPN();
		~RPN();
		void	calculate(const std::string& argv);
	private:
		std::stack<int> _stack;
		RPN(const RPN& instance);
		RPN& operator=(const RPN& instance);
		bool	isOperator(char c);
};

#endif