/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/29 18:56:46 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <sstream>
using std::cout;

BitcoinExchange::BitcoinExchange( const char* price, const char* input ) : _price( 0 ), _priceFilePath( price ), _inputFilePath( input )
{
	checkDataFilePath( _priceFilePath );
	openFiles();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) : _price( other._price )
{
	_priceFilePath = other._priceFilePath;
    _inputFilePath = other._inputFilePath;
	openFiles();
	_bitcoinPrice = other._bitcoinPrice; 
}

BitcoinExchange::~BitcoinExchange()
{
	if (_priceFile.is_open())
		_priceFile.close();
	if (_inputFile.is_open())
		_inputFile.close();
}

BitcoinExchange&	BitcoinExchange::operator= ( const BitcoinExchange& other )
{
	if (this != &other )
	{
		_price = other._price;
		_priceFilePath = other._priceFilePath;
		_inputFilePath = other._inputFilePath;
		openFiles();
		_bitcoinPrice = other._bitcoinPrice;
	}
	return *this;
}

void	BitcoinExchange::readDataFile()
{
	std::string	line;
	
	std::getline(_priceFile, line);
	if (_priceFile.fail() || _priceFile.eof())	//check if is a file not a directory, check if file is empty.
		exitProgram( "read price data file failed" );
	else if (line.compare( "date,exchange_rate" ) == 0)
		std::getline(_priceFile, line);
	while (!line.empty())
	{
		size_t	comma = line.find( ',' );
		std::string date = line.substr( 0, comma );
		std::string price = line.substr( comma + 1 );
		
		if (comma == std::string::npos || !isValidDate( date ) || !isValidPrice( price ))
			exitProgram( "invalid content in price data file" );
		std::pair<std::map<std::string, double>::iterator, bool> result = _bitcoinPrice.insert( std::pair<std::string, double>(date, _price) );
		if (!result.second) // result is a obj not a pointer, it stock return value of _bitcoinPrice.insert().
			exitProgram( "insert new price failed, key already exist" );
		line.clear();
		std::getline(_priceFile, line);
	}
	if (_bitcoinPrice.empty())
		exitProgram( "no price can be read from the price data file" );
}

void	BitcoinExchange::readInputFile()
{
	std::string	line;
	
	std::getline( _inputFile, line );
	if (_inputFile.fail() || _inputFile.eof())
		exitProgram( "read input data file failed" );
	else if (line.compare( "date | value") == 0)
		std::getline( _inputFile, line );
	while (!line.empty())
	{
		try
		{
			size_t	pipe = line.find( '|' );
			if (line.length() > 13 && pipe == 11 && line[pipe + 1]  == ' ' && line[pipe - 1] == ' ')
			{
				std::string	date = line.substr(0, pipe - 1);
				if (!isValidDate( date ))
					throw std::invalid_argument( "invalid date => " + line );
				std::string	value = line.substr(pipe + 2);
				checkValue( value );
				cout << date + " => " + value + " = " << std::endl;
			}
			else
				throw std::invalid_argument( "bad input => " + line );
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << RED << e.what() << std::endl << DEF;
		}
		line.clear();
		std::getline(_inputFile, line);
	}
}	

//**********************************************************************
//						definition of private functions					
// 
//**********************************************************************

void	BitcoinExchange::openFiles()
{
	_priceFile.open( _priceFilePath );
	_inputFile.open( _inputFilePath );
	if (!_priceFile.is_open() || !_inputFile.is_open())
		exitProgram( "open data files failed" );
}

void	BitcoinExchange::checkValue( std::string& value )
{
	int		start = 0;
	int		nb = 0;
	float	fnb = 0.0;
	
	if (value[0] == '+' || value[0] == '-')
		start++;
	else if (value[0] == '-')
		throw std::invalid_argument( "not a positive nb.");

	if (value.find_first_not_of( "0123456789.", start ) != std::string::npos)
		throw std::invalid_argument( "not a nb => " + value );
	size_t	pointPosition = value.find_first_of('.');
	if (pointPosition != std::string::npos && pointPosition != value.find_last_of( '.' ))
		throw std::invalid_argument( "not a nb => " + value );
	std::stringstream	ss( value ); 
	ss >> fnb;
	if (ss.fail())
		throw std::invalid_argument( "too large nb" );
	
	std::stringstream	ss( value );
	ss >> nb;
	if (ss.fail())
		throw std::invalid_argument( "too large nb" );
}

bool	BitcoinExchange::isValidDate( std::string& date )
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++)
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
	if (y < 2009 || y > 2024 || m < 1 || m > 12 || d > 31
		|| ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		|| (y == 2009 && m == 1 && d < 3) // the bitcoin network was created on 3/01/2009.
		|| (m == 2 && y % 400 != 0 && d > 28)
		|| (m == 2 && y % 400 == 0 && d > 29)) // leap year(annee bissextile) had 366days (29days on february).
		return false;
	return true;
}

bool	BitcoinExchange::isValidPrice( std::string& price )
{
	if (price.find_first_not_of( "0123456789." ) != std::string::npos)
		return false;
	size_t	pointPosition = price.find_first_of('.');
	if (pointPosition != std::string::npos && pointPosition != price.find_last_of( '.' ))
		return false;
	std::stringstream	ss( price ); //check if price is not > DBL_MAX. 
	ss >> _price;
	if (ss.fail())
		return false;
	return true;
}

void	BitcoinExchange::exitProgram( const std::string errMsg )
{
	std::cerr << RED << "Error: "<< errMsg << DEF << std::endl;
	BitcoinExchange::~BitcoinExchange();
	exit(EXIT_FAILURE);
}

void	BitcoinExchange::checkDataFilePath( const char*& priceFilePath )
{
	std::string	path( priceFilePath );
	int	len = path.length();
	if (len < 4 || (len == 4 && path.compare( ".csv" ) != 0)
		|| path.substr(len - 4) != ".csv")
		exitProgram( "Price file path not valid" );
	return ;
}