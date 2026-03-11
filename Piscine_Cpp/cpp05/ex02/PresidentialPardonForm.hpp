/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:02:23 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 11:06:17 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include <cstdlib>


class PresidentialPardonForm : public AForm{
public :
	PresidentialPardonForm (const std::string& target);
	PresidentialPardonForm (const PresidentialPardonForm &other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
	~PresidentialPardonForm ();

	void execute(const Bureaucrat& executor) const;
	const std::string& getTarget() const;

private :
	std::string target;
};

#endif