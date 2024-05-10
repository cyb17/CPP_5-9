/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:33:19 by yachen            #+#    #+#             */
/*   Updated: 2024/05/10 18:17:29 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : AForm( "ShrubberyForm", target , 145 , 137)
{
	std::cout << CYAN << this->getName() << " constructor called" << RESET << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm( other )
{
	*this = other;
	std::cout << CYAN << this->getName() << " copy constructor called" << RESET << std::endl;	
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator = ( const ShrubberyCreationForm& other )
{
	if (this != &other)
		AForm::operator = ( other );
	std::cout << CYAN << "assignation operator called" << RESET << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << MAGENTA << this->getName() << " destructor called" << RESET << std::endl;	
}

void	ShrubberyCreationForm::execute( const Bureaucrate& ref ) const
{
	if (this->getSignStatus() == 0)
		throw AForm::GradeTooLowException( this->getName() + " is not signed, can not be executed " );
	else if (ref.getGrade() > this->getReqExeGrade())
		throw AForm::GradeTooLowException( ref.getName() + "'s grade is too low to execute " + this->getName() );
	else
	{
		std::cout << GREEN << this->getName() << " has been executed successfully" << RESET << std::endl;
		this->formAction();
	}
}

void	ShrubberyCreationForm::formAction() const
{
	std::fstream	fs;
	std::string 	file = this->getTarget() + "_shrubberry";

	fs.open( file.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc );
	if (!fs.is_open())
	{
		std::cerr << RED << file << ": open failed " << RESET << std::endl;
		return ;
	}
	this->writeAsciiTree( fs );
	fs.close();
}

void	ShrubberyCreationForm::writeAsciiTree( std::fstream& fs ) const
{
	fs << "	    _-_  "  << std::endl;
	fs << "     /~~   ~~\\  "  << std::endl;
	fs << "  /~~         ~~\\  "  << std::endl;
	fs << " {               }  "  << std::endl;
	fs << "  \\  _-     -_  /  "  << std::endl;
	fs << "    ~  \\ //  ~  "  << std::endl;
	fs << " _- -   | | _- _  "  << std::endl;
	fs << "   _ -  | |   -_  "  << std::endl;
	fs << "       // \\  "  << std::endl;
	fs << "\n					yb" << std::endl;
}