/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:58:47 by yachen            #+#    #+#             */
/*   Updated: 2024/05/01 16:01:08 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

using std::cout;
using std::endl;

Serializer::Serializer()
{
	cout << B_BLUE << "Serializer : Default constructor called" << RESET << endl;
}

Serializer::~Serializer()
{
	cout << B_MAGENTA << "Serializer : Default destructor called" << RESET << endl;
}

Serializer::Serializer( const Serializer& other)
{
	*this = other;
	cout << BLUE << "Serializer : copy constructor called" << RESET << endl;
}

Serializer&	Serializer::operator = ( const Serializer& other )
{
	if ( this != &other )
		*this = other;
	cout << BLUE << "Serializer : operator assignement called" << RESET << endl;
	return *this;
}
