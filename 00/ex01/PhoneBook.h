/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:45:19 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 18:41:37 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"

class PhoneBook {
	private:
			Contact	contactArr[8];
	public:
			int		checkPhoneNumber(std::string phoneNumber);
			void	createNewContact(Contact *contact, int idx);
			void	appendContact(Contact *contact, int idx);
			void	printContacts(void);
			Contact *getContact(int idx);
			void	printOneContact(int idx);
};

#endif