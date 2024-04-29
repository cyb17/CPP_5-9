/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:28:22 by yachen            #+#    #+#             */
/*   Updated: 2024/04/29 11:57:48 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

using std::cout
using std::endl

ScalarConverter::ScalarConverter()
{
	cout << B_BLUE << "ScalarConverter : Default constructor called" << RESET << endl;
}

ScalarConverter::~ScalarConverter()
{
	cout << B_MAGENTA << "ScalarConverter : Default destructor called" << RESET << endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& other)
{
	*this = other;
	cout << BLUE << "ScalarConverter : copy constructor called" << RESET << endl;
}

ScalarConverter&	ScalarConverter::operator = ( const ScalarConverter& other )
{
	cout << BLUE << "ScalarConverter : operator assignement called" << RESET << endl;
	return *this;
}

void ScalarConverter::Convert( std::string str )
{
	
}
