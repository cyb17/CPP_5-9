/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:24:52 by yachen            #+#    #+#             */
/*   Updated: 2024/03/19 12:25:09 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

Bureaucrate::Bureaucrate( const std::string nm, int gd ) : name( nm )
{
	if (gd < 1 || gd > 150)
		throw std::out_of_range(this->name + " initial grade is out of range !");
	this->grade = gd;
	std::cout << this->name << " constructor called" << std::endl;	
}

Bureaucrate::Bureaucrate( const Bureaucrate& other )
{
	*this = other;
	std::cout << this->name << " copy constructor called" << std::endl;	
}

Bureaucrate&	Bureaucrate::operator = ( const Bureaucrate& other )
{
	if (this != &other)
		this->grade = other.getGrade();
	std::cout << this->name << " assignation operator called" << std::endl;	
	return (*this);
}

Bureaucrate::~Bureaucrate()
{
	std::cout << this->name << " destructor called" << std::endl;	
}

const char* Bureaucrate::GradeTooHighException()
const char* Bureaucrate::GradeTooLowException() 


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
		throw std::out_of_range(this->name + " can not incremente, bureaucrate grade will be out of range !");
	this->grade--;
}

void	Bureaucrate::decrementeGrade()
{
	if (this->grade == 150)
		throw std::out_of_range(this->name + " can not decremente, bureaucrate grade will be out of range !");
	this->grade++;
}

std::ostream&	operator<<( std::ostream& os, const Bureaucrate& obj )
{
	os << obj.getName() << ", bureaucrate grade " << obj.getGrade();
	return os;
}
