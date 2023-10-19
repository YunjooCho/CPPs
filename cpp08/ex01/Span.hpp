/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:47:35 by yunjcho           #+#    #+#             */
/*   Updated: 2023/10/19 16:17:45 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
	public:
		Span();
		Span(const unsigned int &n);
		Span(const Span& span);
		Span& operator=(const Span& span);
		~Span();
		void				addNumber(int val);
		int					shortestSpan(void);
		int					longestSpan(void);
		void				addNumbers(const std::vector<int>& args);
		std::vector<int>	getVectors() const;
	private:
		unsigned int		_n;
		std::vector<int>	_vec;
};
#endif