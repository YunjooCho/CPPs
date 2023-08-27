/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:34:58 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/27 21:40:05 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIASOURCE_HPP
# define AMATERIASOURCE_HPP

#include <iostream>
#include "IMaterialSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& materiaSource);
		MateriaSource&	operator=(const MateriaSource &materiaSource);
		virtual ~MateriaSource();
	private:
		virtual void 	learnMateria(AMateria*);
};

#endif