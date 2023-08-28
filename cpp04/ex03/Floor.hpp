/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:28:11 by yunjcho           #+#    #+#             */
/*   Updated: 2023/08/28 20:49:59 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

#include <iostream>
#include "Character.hpp"

Class Floor
{
	public:
		Floor();
		Floor(const Floor& floor);
		Floor&	operator=(const Floor &floor);
		virtual ~Floor();
		AMateria	&getMateriaFromCharac(int idx,  ICharacter& target);
		AMateria	&getMateriaFromTrash(int idx);
		void		setMateriaAtTrash(AMateria &materia);
	private:
		AMateria	*trash[10];
}

#endif