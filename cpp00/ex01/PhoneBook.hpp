/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:47:30 by ssottori          #+#    #+#             */
/*   Updated: 2024/12/02 01:49:33 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int	_size;
		int	_old;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	createCT(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void	addNew(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void	overwriteOld(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void	print_sum(int i);
		void	print_deets(int i);
		int		get_size(void);
};

#endif