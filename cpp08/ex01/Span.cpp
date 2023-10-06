/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:45:10 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/06 19:13:22 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(10) {}

Span::Span(const unsigned int &n) : _n(n) {}

Span& Span::operator=(const Span& span)
{
	if (this != &span)
	{
		_n = span._n;
		_vec.insert(_vec.begin(), span._vec.begin(),  span._vec.end());
	}
	return (*this);
}

Span::Span(const Span& span)
{
	*this = span;
}

Span::~Span() {}

void	Span::addNumber(int val)
{
	if (_n > _vec.size())
		_vec.push_back(val);
	else
		throw std::runtime_error("[Exception::addNumber()] Vector already full");
}

int		Span::shortestSpan(void)
{
	int	result = 0;

	if (_vec.size() <= 1)
		throw std::runtime_error("[Exception::shortestSpan()] Not enough elements");
	std::sort(_vec.begin(), _vec.end());
	result = _vec[1] - _vec[0];
	for (size_t i = 2; i < _vec.size(); i++)
	{
		int span = _vec[i] - _vec[i - 1];
		if (result > span)
			result = span;
	}
	return (result);
}

int		Span::longestSpan(void)
{
	int	result = 0;

	if (_vec.size() <= 1)
		throw std::runtime_error("[Exception::shortestSpan()] Not enough elements");
	std::sort(_vec.begin(), _vec.end());
	result = _vec[_vec.size() - 1] - _vec[0];
	return (result);
}

void	Span::addNumbers(const std::vector<int>& args)
{
	_vec.insert(_vec.begin(), args.begin(), args.end());
}

std::vector<int>	Span::getVectors() const
{
	return (_vec);
}