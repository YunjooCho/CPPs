/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:34:58 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 19:36:01 by yunjcho          ###   ########.fr       */
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
		template <typename AMateria>
		void 		learnMateria(AMateria* materiaSource);                    // IMateriaSource 인터페이스의 추상 메서드 구현
		template <typename AMateria>
		AMateria*	createMateria(std::string const & type);     // IMateriaSource 인터페이스의 추상 메서드 구현
		void		setManualAtIndex(int idx);
		AMateria	*&getManualAtIndex(int idx);
	private:
		AMateria *manual[4];
};

#endif