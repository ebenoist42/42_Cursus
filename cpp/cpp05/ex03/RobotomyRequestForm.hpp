/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenoist <ebenoist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 11:04:35 by ebenoist          #+#    #+#             */
/*   Updated: 2025/12/22 11:05:29 by ebenoist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

public :
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm& operator= (const RobotomyRequestForm& other);
	RobotomyRequestForm (const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const;
	const std::string& getTarjet() const;
	
private :
	std::string target;
};

#endif