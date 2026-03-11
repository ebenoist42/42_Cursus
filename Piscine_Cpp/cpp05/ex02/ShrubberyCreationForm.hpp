/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm..hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:01:59 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 11:05:54 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP
#include "AForm.hpp"
#include <stdexcept>
#include <fstream>

class ShrubberyCreationForm : public AForm{

public :
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	const std::string& getTarget() const;
	void execute(const Bureaucrat& executor) const;

private :
	std::string target;
};

#endif