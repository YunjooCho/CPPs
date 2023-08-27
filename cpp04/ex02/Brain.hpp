/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:43:42 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/26 18:11:55 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& brain);
		Brain&	operator=(const Brain &brain);
		~Brain();
		std::string	getIdea(int	idx) const;
		void		setIdea(std::string idea, int idx);
	private:
		std::string	ideas[100];
};

#endif