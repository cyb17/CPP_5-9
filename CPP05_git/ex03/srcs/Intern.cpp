/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:11:38 by yachen            #+#    #+#             */
/*   Updated: 2024/05/08 13:38:44 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern()
{
	std::cout << CYAN << "Intern constructor called" << RESET << std::endl;	
}

Intern::Intern( const Intern& other )
{
	*this = other;
	std::cout << CYAN << "Intern copy constructor called" << RESET << std::endl;	
}

Intern&	Intern::operator = ( const Intern& other )
{
	std::cout << CYAN << "assignation operator called" << RESET << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

Intern::~Intern()
{
	std::cout << MAGENTA << "Intern destructor called" << RESET << std::endl;	
}

AForm*	Intern::makeForm( const std::string nm, const std::string target )
{
	AForm*			ptr[3];
	std::string		str[3] = {"ShrubberyForm", "RobotomyForm", "PresidentialPardonForm"};
	static ShrubberyCreationForm	f1( target );
	static RobotomyRequestForm		f2( target );
	static PresidentialPardonForm	f3( target );

	ptr[0] = &f1;
	ptr[1] = &f2;
	ptr[2] = &f3;

	for (int i = 0; i < 3; i++)
	{
		if (nm == str[i])
		{
			std::cout << GREEN << "Intern creates " << ptr[i]->getName() << " target on " << ptr[i]->getTarget() << RESET << std::endl;
			return ptr[i];
		}
	}
	std::cout << RED << "Intern can't creates " << nm << ": Unknown form" << RESET << std::endl;
	return NULL;
}
