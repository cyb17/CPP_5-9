/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ForAm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:20:29 by yachen            #+#    #+#             */
/*   Updated: 2024/03/20 11:15:51 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrate.hpp"

AForm::AForm( const std::string nm, const std::string target, const int signGrade, const int exeGrade ) : name( nm ), target( target ), reqSignGrade( signGrade ), reqExeGrade( exeGrade )
{
	if (signGrade < 1)
		throw AForm::GradeTooHighException( this->name + ": initial sign grade is too high");
	else if (signGrade > 150)
		throw AForm::GradeTooLowException( this->name + ": initial sign grade is too low" );
	else if (exeGrade < 1)
		throw AForm::GradeTooHighException( this->name + ": initial execution grade is too high");
	else if (exeGrade > 150)
		throw AForm::GradeTooLowException( this->name + ": initial execution grade is too low" );
	this->signStatus = 0;
	std::cout << CYAN << this->name << " constructor called" << RESET << std::endl;	
}

AForm::AForm( const AForm& other ) : name( other.name ), reqSignGrade( other.reqSignGrade ), reqExeGrade( other.reqExeGrade )
{
	*this = other;
	std::cout << CYAN << this->name << " copy constructor called" << RESET << std::endl;	
}

AForm&	AForm::operator = ( const AForm& other )
{
	if (this != &other)
		this->signStatus = other.getSignStatus();
	std::cout << CYAN << "assignation operator called" << RESET << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << MAGENTA << this->name << " destructor called" << RESET << std::endl;	
}

const std::string	AForm::getName() const
{
	return this->name;
}

const std::string	AForm::getTarget() const
{
	return this->target;
}

bool	AForm::getSignStatus() const
{
	return this->signStatus;
}

int		AForm::getReqSignGrade() const
{
	return this->reqSignGrade;
}

int		AForm::getReqExeGrade() const
{
	return this->reqExeGrade;
}

void	AForm::beSigned( Bureaucrate& ref )
{
	if (ref.getGrade() <= this->reqSignGrade)
	{
		this->signStatus = true;
		std::cout << GREEN << this->name << " is signed by " << ref.getName() << RESET << std::endl;
	}
	else
		throw AForm::GradeTooLowException( ref.getName() + "'grade is to low to sign " + this->name );
}

std::ostream&	operator<<( std::ostream& os, const AForm& obj )
{
	os << BLUE << obj.getName() << " sign status: " << obj.getSignStatus() << ": require: grade "<< obj.getReqSignGrade() << " for signing, grade " << obj.getReqExeGrade() << " for execution " << RESET;
	return os;
}

AForm::GradeTooHighException::GradeTooHighException( const std::string msg ) throw() : errMsg( msg ) {}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::GradeTooLowException( const std::string msg ) throw() : errMsg( msg ) {}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (errMsg.c_str());
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (errMsg.c_str());
}