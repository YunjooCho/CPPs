/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 22:07:48 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/29 16:58:40 by yunjcho          ###   ########.fr       */
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

	std::stringstream	ss(argv);
	std::string 		inputStr;
	int	operCnt = 0;

	if (std::string(argv).length() < 2)
		throw std::runtime_error("Error: not enough elements.");
	while (ss >> inputStr)
	{
		char c = inputStr.c_str()[0];
		if (inputStr.size() > 1)
			throw std::runtime_error("Error");
		else if (std::isdigit(c))
		{
			_stack.push(c - '0');
		}
		else if (isOperator(c) == true)
		{
			++operCnt;
			if (_stack.size() < 2)
				throw std::runtime_error("Error: not enough numbers elements.");
			int num2 = _stack.top();
			_stack.pop();
			int num1 = _stack.top();
			_stack.pop();
			if (c == '+')
				_stack.push(num1 + num2);
			else if (c == '-')
			{
				_stack.push(num1 - num2);
			}
			else if (c == '/')
			{
				if (num2 == 0)
					throw std::runtime_error("Error: You cannot divide by zero.");
				_stack.push(num1 / num2);
			}
			else if (c == '*')
			{
				_stack.push(num1 * num2);
			}
		}
		else
			throw std::runtime_error("Error");
	}
	if (operCnt == 0)
		throw std::runtime_error("Error: Operator is required.");
	if (_stack.size() == 1)
	{
		std::cout << _stack.top() << std::endl;
	}
	else
		throw std::runtime_error("Error: Stack does not have just one element.");
}