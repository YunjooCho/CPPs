/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:34:58 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/29 00:39:21 by yunjcho          ###   ########seoul.kr  */
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
		void 		learnMateria(AMateria* materiaSource);                    // IMateriaSource 인터페이스의 추상 메서드 구현
		AMateria	*createMateria(std::string const & type);                 // IMateriaSource 인터페이스의 추상 메서드 구현
	private:
		AMateria *manual[4];
};

#endif