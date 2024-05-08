/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:20:29 by yachen            #+#    #+#             */
/*   Updated: 2024/05/08 12:42:29 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrate.hpp"

Form::Form( const std::string nm, const int signGrade, const int exeGrade ) : name( nm ), reqSignGrade( signGrade ), reqExeGrade( exeGrade )
{
	if (signGrade < 1)
		throw Form::GradeTooHighException( this->name + ": initial sign grade is too high");
	else if (signGrade > 150)
		throw Form::GradeTooLowException( this->name + ": initial sign grade is too low" );
	else if (exeGrade < 1)
		throw Form::GradeTooHighException( this->name + ": initial execution grade is too high");
	else if (exeGrade > 150)
		throw Form::GradeTooLowException( this->name + ": initial execution grade is too low" );
	this->signStatus = 0;
	std::cout << CYAN << this->name << " constructor called" << RESET << std::endl;	
}

Form::Form( const Form& other ) : name( other.name ), reqSignGrade( other.reqSignGrade ), reqExeGrade( other.reqExeGrade )
{
	*this = other;
	std::cout << CYAN << this->name << " copy constructor called" << RESET << std::endl;	
}

Form&	Form::operator = ( const Form& other )
{
	if (this != &other)
		this->signStatus = other.getSignStatus();
	std::cout << CYAN << "assignation operator called" << RESET << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << MAGENTA << this->name << " destructor called" << RESET << std::endl;	
}

const std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getSignStatus() const
{
	return this->signStatus;
}

int		Form::getReqSignGrade() const
{
	return this->reqSignGrade;
}

int		Form::getReqExeGrade() const
{
	return this->reqExeGrade;
}

void	Form::beSigned( Bureaucrate& ref )
{
	if (ref.getGrade() <= this->reqSignGrade)
	{
		this->signStatus = true;
		std::cout << GREEN << this->name << " is signed by " << ref.getName() << RESET << std::endl;
	}
	else
		throw Form::GradeTooLowException( ref.getName() + "'grade is to low to sign " + this->name );
}

std::ostream&	operator<<( std::ostream& os, const Form& obj )
{
	os << BLUE << obj.getName() << " sign status: " << obj.getSignStatus() << ": require: grade "<< obj.getReqSignGrade() << " for signing, grade " << obj.getReqExeGrade() << " for execution " << RESET;
	return os;
}

Form::GradeTooHighException::GradeTooHighException( const std::string msg ) throw() : errMsg( msg ) {}
Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::GradeTooLowException( const std::string msg ) throw() : errMsg( msg ) {}
Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Form::GradeTooHighException::what() const throw()
{
	return (errMsg.c_str());
}

const char* Form::GradeTooLowException::what() const throw()
{
	return (errMsg.c_str());
}