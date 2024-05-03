/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:58:47 by yachen            #+#    #+#             */
/*   Updated: 2024/05/03 11:56:51 by yachen           ###   ########.fr       */
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

uintptr_t*	Serializer::serialize( Data* ptr )
{
	return reinterpret_cast<uintptr_t*>(ptr);
}

Data*	Serializer::deserialize(uintptr_t* raw)
{
	return reinterpret_cast<Data*>(raw);
}
