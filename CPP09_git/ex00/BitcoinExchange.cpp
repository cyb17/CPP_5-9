/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/28 19:07:38 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
using std::cout;

BitcoinExchange::BitcoinExchange( const std::string path ) : _path( path )
{
	cout << "cs\n";
	if (!isValidPath())
		exitProgram( "Invalid data file path" );
	_dataFile.open( _path.c_str() );
	if (!_dataFile.is_open())
		exitProgram( "Open data file failed" );
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) : _bitcoinPrice( other._bitcoinPrice ) {}

BitcoinExchange::~BitcoinExchange()
{
	if (_dataFile.is_open())
		_dataFile.close();
	cout << "ds\n";
}

BitcoinExchange&	BitcoinExchange::operator= ( const BitcoinExchange& other )
{
	if (this != &other )
		_bitcoinPrice = other._bitcoinPrice;
	return *this;
}

void	BitcoinExchange::readFile()
{
	std::string	line;
	std::getline(_dataFile, line);
	if (_dataFile.fail() || _dataFile.eof())	//check if is a file not a directory, check if file is empty.
		exitProgram( "Read data file failed" );
	if (line.compare( "date,exchange_rate" ) == 0)
		std::getline(_dataFile, line);	
	while (!line.empty())
	{
		size_t	comma = line.find( ',' );
		if (comma == std::string::npos || !isValidDate( line.substr( 0, comma )))
		{
			cout << line.substr( 0,comma ) << '\n';
			exitProgram( "Invalid content format in data file" );
		}
		// isValidPrice( line.substr(comma + 1) );
		line.clear();
		std::getline(_dataFile, line);
	}
}

void	BitcoinExchange::exitProgram( const char* errMsg )
{
	std::cerr << RED << errMsg << DEF << std::endl;
	BitcoinExchange::~BitcoinExchange();
	exit(EXIT_FAILURE);
}

bool	BitcoinExchange::isValidPath()
{
	int	len = _path.length();
	if (len < 4 || (len == 4 && _path.compare( ".csv" ) != 0)
		|| _path.substr(len - 4) != ".csv")
		return false;
	return true;
}

bool	BitcoinExchange::isValidDate( std::string date )
{
	if (date.length() != 10)
	{
		cout << "1\n";
		return false;
	}
	if (date[4] != '-' || date[7] != '-')
	{
		cout << "2\n";
		return false;
	}
	for (size_t i = 0; i < date.length(); i++)
	{
		if ((date[i] < '0' || date[i] > '9') && i != 4 && i != 7 && i != 10)
		{
			cout << "3\n";
			return false;
		}
	}
	std::string	years = date.substr( 0, 4 );
	std::string	month = date.substr( 5, 2 );
	std::string	day = date.substr( 8, 2 );
	int	y = atoi( years.c_str() );
	int	m = atoi( month.c_str() );
	int	d = atoi( day.c_str() );
	if (y < 2009 || y > 2024 || m < 1 || m > 12 || d > 31)
	{
		cout << "4\n";
		return false;
	}
	if (y == 2009 && m == 1 && d < 3) // the bitcoin network was created on 3/01/2009.
	{
		cout << "5\n";
		return false;
	}
	if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
	{
		cout << "6\n";
		return false;
	}
	if (m == 2 && y % 400 != 0 && d > 28)
	{
		cout << "7\n";
		return false;
	}
	if (m == 2 && y % 400 == 0 && d > 29) // leap year(annee bissextile) had 366days (29days on february).
	{
		cout << "8\n";
		return false;
	}
	return true;
}

// bool	BitcoinExchange::isValidPrice( std::string price )
// {
// 	if (price.find_first_not_of( "0123456789." ) != std::string::npos)
// 		return false;
// 	int	pointPosition = price.find_first_of('.', 0);
// 	if (point == std::string::npos)
// 	{
// 		//check la valeur 
// 	}
// 	else
// 	{
// 		if (pointPosition != price.find_last_of('.', 0)
// 			|| pointPosition == 0 || pointPosition == price.length() - 1)
// 			return false;
// 	}
// }


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
