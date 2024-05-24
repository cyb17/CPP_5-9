/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/24 17:56:30 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
using std::cout;

BitcoinExchange::BitcoinExchange() {cout << "cs\n";}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) : _bitcoinPrice( other._bitcoinPrice ) {}

BitcoinExchange::~BitcoinExchange() {cout << "ds\n";}

BitcoinExchange&	BitcoinExchange::operator= ( const BitcoinExchange& other )
{
	if (this != &other )
		_bitcoinPrice = other._bitcoinPrice;
	return *this;
}

void	BitcoinExchange::readFile()
{
	std::ifstream	ifs( "tete/correctFile" );
	if (!ifs.is_open())
	{
		std::cerr << RED << "Open data file failed\n" << DEF;
		BitcoinExchange::~BitcoinExchange();
		exit(EXIT_FAILURE);
	}
	std::string					line;
	int							i = 0;
	while (std::getline(ifs, line))
	{
		// _fileContent[i++] = line;
		// line.clear();
		int	comma = line.find( ',' );
		isValidDate( line.substr( 0, comma ));
	}
	ifs.close();
}

bool	BitcoinExchange::isValidPrice( std::string price )
{
	if (price.find_first_not_of( "0123456789." ) != std::string::npos)
		return false;
	int	point = price.find('.', 0);
	if (point == std::string::npos)
	{
		//check la valeur 
	}
	else
	{
		if (price.find_first_of('.'))
		if (point == 0 || point == price.length() - 1)
		return false;
	}
}

bool	BitcoinExchange::isValidDate( std::string& date )
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-' || date[10] != ',')
		return false;
	for (int i = 0; i < date.length(); i++)
	{
		if ((date[i] < '0' || date[i] > '9') && i != 4 && i != 7 && i != 10)
			return false;
	}
	std::string	years = date.substr( 0, 4 );
	std::string	month = date.substr( 5, 2 );
	std::string	day = date.substr( 8, 2 );
	int	y = atoi( years.c_str() );
	int	m = atoi( month.c_str() );
	int	d = atoi( day.c_str() );
	if (y < 2009 || y > 2024 || m < 1 || m > 12 || d > 31)
		return false;
	if (y == 2009 && d < 3) // the bitcoin network was created on 3/01/2009.
		return false;
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		return false;
	if (m == 2 && y % 400 != 0 && d > 28)
		return false;
	if (m == 2 && y % 400 == 0 && d > 29) // leap year(annee bissextile) had 366days (29days on february).
		return false;
	return true;
}

// void	BitcoinExchange::analyzeFileContent()
// {
// 	std::string	date;
// 	std::string	price;
	
// 	std::map<int, std::string>::iterator	it = _fileContent.begin();
// 	for (; it != _fileContent.end(); it++)
// 	{
// 		int	comma = it->
// 		cout << "key : " << it->first << "value:" << it->second <<'\n';
// 	}

// }
