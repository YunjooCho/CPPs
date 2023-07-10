/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:18:24 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/10 18:37:23 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>

class Contact {
	private:
			std::string	firstName;
			std::string	lastName;
			std::string	nickname;
			std::string	phoneNumber;
			std::string	darkestSecret;
	public:
		void 		setVariables(std::string firstName, \
						std::string lastName, std::string nickname, \
						std::string phoneNumber, std::string darkestSecret);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
		void		chagePrintString(std::string str);
};

#endif