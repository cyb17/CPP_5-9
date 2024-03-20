/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:33:19 by yachen            #+#    #+#             */
/*   Updated: 2024/03/20 13:57:32 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShruberryCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string nm ) : AForm( nm , 145 , 137)
{
	std::cout << CYAN << this->name << " constructor called" << RESET << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm( other )
{
	*this = other;
	std::cout << CYAN << this->name << " copy constructor called" << RESET << std::endl;	
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator = ( const ShrubberyCreationForm& other )
{
	if (this != &other)
		AForm::operator = ( other )
	std::cout << CYAN << "assignation operator called" << RESET << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << MAGENTA << this->name << " destructor called" << RESET << std::endl;	
}

void	ShrubberyCreationForm::formAction()
{
	std::fstream	fs;
	std::string 	file = this->name + "shruberry";

	fs.open( file.c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc )
	if (!fs.is_open())
	{
		std::cerr << RED << file << ": open failed " << RESET << std::endl;
		return ;
	}
	this->writeTrees( fs );
	fs.close();
}

void	ShrubberyCreationForm::writeTrees( std::fstream fs )
{
	
}