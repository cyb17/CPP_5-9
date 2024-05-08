/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:48:56 by yachen            #+#    #+#             */
/*   Updated: 2024/05/08 13:24:10 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

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
	if (this->getSignStatus() == 0)
		throw AForm::GradeTooLowException( this->getName() + " is not signed, can not be executed " );
	else if (ref.getGrade() > this->getReqExeGrade())
		throw AForm::GradeTooLowException( ref.getName() + "'s grade is too low to execute " + this->getName() );
	else
	{
		srand(time(NULL));
		int nb = rand() % 2;
		if (nb == 0)
			std::cout << GREEN << this->getTarget() << " has been robotomized successfully 50% of the time. " << RESET << std::endl;
		else
			std::cout << GREEN << "Robotomy failed." << RESET << std::endl;
	}
}
