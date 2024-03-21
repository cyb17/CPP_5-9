/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:33:19 by yachen            #+#    #+#             */
/*   Updated: 2024/03/21 11:33:44 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string nm ) : AForm( nm , 145 , 137)
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
	if (ref.getGrade() <= this->getReqSignGrade() && ref.getGrade() <= this->getReqExeGrade())
		this->formAction();
	else
		throw AForm::GradeTooLowException( ref.getName() + "'s grade is too low to execute " + this->getName() );
}

void	ShrubberyCreationForm::formAction() const
{
	std::fstream	fs;
	std::string 	file = this->getName() + "_shrubberry";

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