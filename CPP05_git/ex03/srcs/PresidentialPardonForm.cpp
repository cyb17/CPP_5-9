/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:01:37 by yachen            #+#    #+#             */
/*   Updated: 2024/05/07 16:41:04 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : AForm( "PresidentialPardonForm", target , 25 , 5)
{
	std::cout << CYAN << this->getName() << " constructor called" << RESET << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm( other )
{
	*this = other;
	std::cout << CYAN << this->getName() << " copy constructor called" << RESET << std::endl;	
}

PresidentialPardonForm&	PresidentialPardonForm::operator = ( const PresidentialPardonForm& other )
{
	if (this != &other)
		AForm::operator = ( other );
	std::cout << CYAN << "assignation operator called" << RESET << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << MAGENTA << this->getName() << " destructor called" << RESET << std::endl;	
}

void	PresidentialPardonForm::execute( const Bureaucrate& ref ) const
{
	try
	{
		if (ref.getGrade() <= this->getReqSignGrade() && ref.getGrade() <= this->getReqExeGrade())
			std::cout << GREEN << this->getTarget() << " has been pardoned by Zaphod Beeblebrox. " << RESET << std::endl;
		else
			throw AForm::GradeTooLowException( ref.getName() + "'s grade is too low to execute " + this->getName() );
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}