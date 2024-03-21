/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:48:56 by yachen            #+#    #+#             */
/*   Updated: 2024/03/21 13:59:09 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm( "RobotomyForm", target , 72 , 45)
{
	std::cout << CYAN << this->getName() << " constructor called" << RESET << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm( other )
{
	*this = other;
	std::cout << CYAN << this->getName() << " copy constructor called" << RESET << std::endl;	
}

RobotomyRequestForm&	RobotomyRequestForm::operator = ( const RobotomyRequestForm& other )
{
	if (this != &other)
		AForm::operator = ( other );
	std::cout << CYAN << "assignation operator called" << RESET << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << MAGENTA << this->getName() << " destructor called" << RESET << std::endl;	
}

void	RobotomyRequestForm::execute( const Bureaucrate& ref ) const
{
	if (ref.getGrade() <= this->getReqSignGrade() && ref.getGrade() <= this->getReqExeGrade())
		std::cout << GREEN << this->getTarget() << " has been robotomized successfully 50% of the time. " << RESET << std::endl;
	else
		throw AForm::GradeTooLowException( "Robotomy failed." );
}
