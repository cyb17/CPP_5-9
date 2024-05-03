/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:35:11 by yachen            #+#    #+#             */
/*   Updated: 2024/05/03 12:02:51 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

using std::cout;
using std::endl;

Data::Data( int i, char c ) : i( i ), c( c )
{
	cout << B_BLUE << "Data : Default constructor called" << RESET << endl;
}

Data::~Data()
{
	cout << B_MAGENTA << "Data : Default destructor called" << RESET << endl;
}

Data::Data( const Data& other)
{
	*this = other;
	cout << BLUE << "Data : copy constructor called" << RESET << endl;
}

Data&	Data::operator = ( const Data& other )
{
	if ( this != &other )
	{
		this->i = other.i;
		this->c = other.c;
	}
	cout << BLUE << "Data : operator assignement called" << RESET << endl;
	return *this;
}

int	Data::getI() const
{
	return i;
}

char	Data::getC() const
{
	return c;
}