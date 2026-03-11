/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:58:56 by ebenoist          #+#    #+#             */
/*   Updated: 2025/11/21 11:56:39 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <sstream>


class PhoneBook
{
	private :
		Contact _contacts[8];
		int		_index;

	public :
		PhoneBook();
		~PhoneBook();
		void	addcontact();
		void	displaycontacts()const;
		void	displayonecontact(int index)const;
		int		getindex()const;
};

#endif