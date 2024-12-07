/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:45:13 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/02 02:00:14 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cctype>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;

	public:
		Contact(void);
		~Contact(void);
		void	save(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void	print_short(int i);
		void	print_long(int i);
};

/*public: can be accessed from outside the class 
private: can only be accessed by the class itself
*/

#endif