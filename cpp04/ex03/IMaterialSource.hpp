/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMaterialSource.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:33:29 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 20:40:20 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	IMATERIALSOURCE_HPP
# define IMATERIALSOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void 		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif