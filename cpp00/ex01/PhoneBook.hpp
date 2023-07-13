/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:45:19 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/13 12:28:51 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

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