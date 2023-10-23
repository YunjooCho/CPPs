/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:07:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/23 23:31:54 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

//private
RPN& RPN::operator=(const RPN& instance)
{
	if (this != &instance)
	{
		_stack = instance._stack;
	}
	return (*this);
}

//private
RPN::RPN(const RPN& instance)
{
	*this = instance;
}

bool	RPN::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

void	RPN::calculate(const std::string& argv)
{
	int	operCnt = 0;

	for (size_t i = 0; i < argv.length(); i++)
	{
		if (argv[i] == ' ')
			continue ;
		else if (std::isdigit(argv[i]))
		{
			_stack.push(argv[i] - '0');
		}
		else if (isOperator(argv[i]) == true)
		{
			++operCnt;
			if (_stack.size() < 2)
				throw std::runtime_error("Error: not enough numbers elements.");
			int num2 = _stack.top();
			_stack.pop();
			int num1 = _stack.top();
			_stack.pop();
			if (argv[i] == '+')
				_stack.push(num1 + num2);
			else if (argv[i] == '-')
				_stack.push(num1 - num2);
			else if (argv[i] == '/')
			{
				if (num2 == 0)
					throw std::runtime_error("Error: You cannot divide by zero.");
				_stack.push(num1 / num2);
			}
			else if (argv[i] == '*')
			{
				_stack.push(num1 * num2);
			}
		}
		else
			throw std::runtime_error("Error");
	}
	if (operCnt == 0)
		throw std::runtime_error("Error: At least one operator is required.");
	std::cout << _stack.top() << std::endl;
}
