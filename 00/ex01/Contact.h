/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunjcho <yunjcho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:18:24 by yunjcho           #+#    #+#             */
/*   Updated: 2023/07/06 20:28:03 by yunjcho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
	private:
			int			id;
			std::string	firstName;
			std::string	lastName;
			std::string	nickname;
			std::string	phoneNumber;
			std::string	darkestSecret;
	public:
		void setVariables(int idx, std::string firstName, \
			std::string lastName, std::string nickname, \
			std::string phoneNumber, std::string darkestSecret);
		std::string	getFirstName(void);
		std::string	getLasttName(void);
		std::string	getNickname(void);
};

#endif