/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:20:32 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/09 17:14:10 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack() : std::stack<T, Container>() {};
		MutantStack(const MutantStack& stack) : std::stack<T, Container>(stack)
		{
			*this = stack;
		}
		MutantStack& operator=(const MutantStack& stack)
		{
			if (this != &stack)
			{
				this->c = stack.c;
				// this->c.insert(this->c.begin(), stack.c.begin(),  stack.c.end()); //안되면 for문으로 복사
			}
			return (*this);
		}
		~MutantStack() {}
		void		push(const T& val)
		{
			this->c.push_back(val);
		}
		void		pop(void)
		{
			this->c.pop_back();
		}
		std::size_t	size(void)
		{
			return (this->c.size());
		}
		const T&	top(void) const
		{
			return (this->c[this->c.size() - 1]);
		}
		typename Container<typename T>::iterator begin()
		{
			return this->c.begin();
		}
		typename Container<typename T>::iterator end()
		{
			return this->c.end();
		}
};

#endif