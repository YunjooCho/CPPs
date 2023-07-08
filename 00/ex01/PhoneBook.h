/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:45:19 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/08 18:18:02 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook {
	private:
			Contact	contactArr[8];
	public:
			void	appendContact(int idx, Contact *contact);
			Contact *getContact(int idx);
			void	printContacts(void);
			void	printOneContact(int idx);

};

#endif