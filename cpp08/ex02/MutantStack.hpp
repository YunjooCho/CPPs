/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:20:32 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/09 19:37:56 by yunjcho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		typedef typename Container::iterator 	iterator;
		typedef typename Container::size_type	size_c;

		MutantStack() : std::stack<T, Container>() {};

		MutantStack(const MutantStack& stack) : std::stack<T, Container>(stack)
		{
			*this = stack;
		}

		MutantStack& operator=(const MutantStack& stack)
		{
			if (this != &stack)
				this->c = stack.c;
			return (*this);
		}

		~MutantStack() {}

		void push(const T& value) 
		{
			this->c.push_back(value);
		}

		void pop(void) 
		{
			this->c.pop_back();
		}

		const T& top(void) const
		{
			return (this->c.back());
		}

		size_c size(void) const 
		{
			return (this->c.size());
		}

		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}
};

#endif