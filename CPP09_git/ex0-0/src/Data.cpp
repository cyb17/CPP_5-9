/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:19:59 by yachen            #+#    #+#             */
/*   Updated: 2024/05/24 11:34:50 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "iostream"
#include "ifstream"
#include "iterator"
#include <stdlib>
using std::cout;

Data::Data( std::string path ) : path( path ) {}

Data::Data( const Data& other ) : path( other.path ), content( other.content ) {}

Data::~Data() {}

Data&	Data::operator= ( const Data& other )
{
	if (this != &other )
	{
		path = other.path;
		content = other.content;
	}
	return *this;
}

void	Data::readData() const
{
	std::ifstream	ifs( path );
	if (!ifs.is_open())
	{
		std::cerr << RED << "Open data file failed\n"; << RESET;
		exit(EXIT_FAILURE);
	}
	std::string	line;
	while (std::getline(ifs, line))
	{
		check
	}
}