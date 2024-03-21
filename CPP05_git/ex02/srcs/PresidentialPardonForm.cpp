/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:01:37 by yachen            #+#    #+#             */
/*   Updated: 2024/03/21 12:03:44 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string nm ) : AForm( nm , 25 , 5)
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
	if (ref.getGrade() <= this->getReqSignGrade() && ref.getGrade() <= this->getReqExeGrade())
		std::cout << GREEN << ref.getName() << " has been pardoned by Zaphod Beeblebrox. " << RESET << std::endl;
	else
		throw AForm::GradeTooLowException( ref.getName() + "'s grade is too low to execute " + this->getName() );
}