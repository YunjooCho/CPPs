/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:04:49 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/23 23:01:35 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
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