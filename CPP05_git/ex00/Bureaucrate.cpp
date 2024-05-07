/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:24:52 by yachen            #+#    #+#             */
/*   Updated: 2024/05/07 16:07:56 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

Bureaucrate::Bureaucrate( const std::string nm, int gd ) : name( nm )
{
	std::cout << CYAN << this->name << " constructor called" << RESET << std::endl;	
	try
	{
		if (gd < 1)
			throw Bureaucrate::GradeTooHighException( this->name + ": initial grade is too high");
		else if (gd > 150)
			throw Bureaucrate::GradeTooLowException( this->name + ": initial grade is too low" );
		this->grade = gd;
	}
	catch (Bureaucrate::GradeTooHighException& e)
	{
		std::cout << RED << "Exception: " << e.what() << std::endl;
	}
	catch (Bureaucrate::GradeTooLowException& e)
	{
		std::cout << RED << "Exception: " << e.what() << std::endl;
	}
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
	try
	{
		if (this->grade == 1)
			throw Bureaucrate::GradeTooHighException( this->name + ": can not incremente, grade will be too high" );
		this->grade--;
	}
	catch (Bureaucrate::GradeTooHighException& e)
	{
		std::cout << RED << "Exception: " << e.what() << std::endl;
	}
}

void	Bureaucrate::decrementeGrade()
{
	try
	{
		if (this->grade == 150)
			throw Bureaucrate::GradeTooLowException( this->name + ": can not decremente, grade will be too low" );
		this->grade++;
	}
	catch (Bureaucrate::GradeTooLowException& e)
	{
		std::cout << RED << "Exception: " << e.what() << std::endl;
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

