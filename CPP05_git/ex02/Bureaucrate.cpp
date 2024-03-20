/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:24:52 by yachen            #+#    #+#             */
/*   Updated: 2024/03/20 10:27:46 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"
#include "Form.hpp"

Bureaucrate::Bureaucrate( const std::string nm, int gd ) : name( nm )
{
	if (gd < 1)
		throw Bureaucrate::GradeTooHighException( this->name + ": grade initial is too high");
	else if (gd > 150)
		throw Bureaucrate::GradeTooLowException( this->name + ": grade initial is too low" );
	this->grade = gd;
	std::cout << CYAN << this->name << " constructor called" << RESET << std::endl;	
}

Bureaucrate::Bureaucrate( const Bureaucrate& other ) : name( other.name )
{
	*this = other;
	std::cout << CYAN << this->name << " copy constructor called" << RESET << std::endl;	
}

Bureaucrate&	Bureaucrate::operator = ( const Bureaucrate& other )
{
	if (this != &other)
		this->grade = other.getGrade();
	std::cout << CYAN << "assignation operator called" << RESET << std::endl;
	return (*this);
}

Bureaucrate::~Bureaucrate()
{
	std::cout << MAGENTA << this->name << " destructor called" << RESET << std::endl;	
}

const std::string	Bureaucrate::getName() const
{
	return this->name;
}

int	Bureaucrate::getGrade() const
{
	return this->grade;	
}

void	Bureaucrate::incrementeGrade()
{
	if (this->grade == 1)
		throw Bureaucrate::GradeTooHighException( this->name + ": can not incremente, grade will be too high" );
	this->grade--;
}

void	Bureaucrate::decrementeGrade()
{
	if (this->grade == 150)
		throw Bureaucrate::GradeTooLowException( this->name + ": can not decremente, grade will be too low" );
	this->grade++;
}

void	Bureaucrate::signForm( Form& ref )
{
	if (this->grade <= ref.getReqSignGrade())
		std::cout << GREEN << this->name << " signed " << ref.getName() << RESET << std::endl;
	else
	{
		std::cout << RED << this->name << " couldn't sign " << ref.getName() << " because ";
		std::cout << this->name << "'s grade is too low " << RESET << std::endl;
	} 
}

std::ostream&	operator<<( std::ostream& os, const Bureaucrate& obj )
{
	os << BLUE << obj.getName() << ", bureaucrate grade " << obj.getGrade() << RESET;
	return os;
}

Bureaucrate::GradeTooHighException::GradeTooHighException( const std::string msg ) throw() : errMsg( msg ) {}
Bureaucrate::GradeTooHighException::~GradeTooHighException() throw() {}

Bureaucrate::GradeTooLowException::GradeTooLowException( const std::string msg ) throw() : errMsg( msg ) {}
Bureaucrate::GradeTooLowException::~GradeTooLowException() throw() {}

const char* Bureaucrate::GradeTooHighException::what() const throw()
{
	return (errMsg.c_str());
}

const char* Bureaucrate::GradeTooLowException::what() const throw()
{
	return (errMsg.c_str());
}

