/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/31 12:59:27 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <sstream>
using std::cout;

BitcoinExchange::BitcoinExchange( const char* price, const char* input ) : _price( 0.0 ), _priceFilePath( price ), _inputFilePath( input )
{
	if (!isValidDataFilePath( _priceFilePath ))
		throw std::invalid_argument( "price file path not valid" );
	if (!openFiles())
		throw std::invalid_argument( "open data files failed" );
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) : _price( other._price )
{
	_priceFilePath = other._priceFilePath;
    _inputFilePath = other._inputFilePath;
	if (!openFiles())
		throw std::invalid_argument( "open data files failed" );
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
		if (_priceFile.is_open())
			_priceFile.close();
		if (_inputFile.is_open())
			_inputFile.close();
		if (!_bitcoinPrice.empty())
			_bitcoinPrice.clear();
		if (!openFiles())
			throw std::invalid_argument( "open data files failed" );
	}
	return *this;
}

void	BitcoinExchange::exchangeBitcoin()
{
	readDataFile();
	readInputFile();
}

//**********************************************************************
//						definition of private functions					
// 
//**********************************************************************

void	BitcoinExchange::readDataFile()
{
	std::string	line;
	std::getline(_priceFile, line);
	if (_priceFile.fail() || _priceFile.eof())								// check if is a file not a directory, check if file is empty.
		throw std::invalid_argument( "read price data file failed" );
	else if (line.compare( "date,exchange_rate" ) == 0)						// allow the existence of "date,exchange_rage" but only as first line.
		std::getline(_priceFile, line);
	while (!line.empty())
	{
		size_t	comma = line.find( ',' );
		std::string date = line.substr( 0, comma );
		std::string price = line.substr( comma + 1 );
		
		if (comma == std::string::npos || !isValidDate( date ) || !isValidPrice( price ))
			throw std::invalid_argument( "invalid content in price data file" );
		std::pair<std::map<std::string, double>::iterator, bool> result;			// result is a obj, stock return value(->a iterator and a bool) of insert().
		result = _bitcoinPrice.insert( std::pair<std::string, double>(date, _price) );
		if (!result.second)		 											
			throw std::invalid_argument( "insert new price failed, key already exist" );
		line.clear();
		std::getline(_priceFile, line);
	}
	if (_bitcoinPrice.empty())
		throw std::invalid_argument( "no price can be read from the price data file" );
}

void	BitcoinExchange::readInputFile()
{
	std::string	line;
	std::getline( _inputFile, line );
	if (_inputFile.fail() || _inputFile.eof())
		throw std::invalid_argument( "read input data file failed" );
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
				printExchangedBitcoin( date, value );
			}
			else
				throw std::invalid_argument( "bad input => " + line );
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << RED << "Error: " << e.what() << std::endl << DEF;
		}
		line.clear();
		std::getline(_inputFile, line);
	}
}

bool	BitcoinExchange::isValidDataFilePath( const char*& priceFilePath )
{
	std::string	path( priceFilePath );
	int	len = path.length();
	if (len < 4 || (len == 4 && path.compare( ".csv" ) != 0) || path.substr(len - 4) != ".csv")
		return false;
	return true;
}

bool	BitcoinExchange::openFiles()
{
	_priceFile.open( _priceFilePath );
	_inputFile.open( _inputFilePath );
	if (!_priceFile.is_open() || !_inputFile.is_open())
		return false;
	return true;
}

void	BitcoinExchange::checkValue(  const std::string& value )
{
	int		start = 0;
	if (value[0] == '+')
		start++;
	else if (value[0] == '-')
		throw std::invalid_argument( "not a positive number => " + value);
	if (value.find_first_not_of( "0123456789.", start ) != std::string::npos)
		throw std::invalid_argument( "not a number => " + value );
	size_t	pointPosition = value.find_first_of('.');
	std::stringstream	ss( value );
	if (pointPosition == std::string::npos)
	{
		int	nb;
		ss >> nb;
		if (nb > 1000 || ss.fail())	
			throw std::invalid_argument( "too large number" );
	}
	else if (pointPosition == value.find_last_of( '.' ))
	{
		float	fnb;
		ss >> fnb;
		if (fnb > 1000.0f || ss.fail())
			throw std::invalid_argument( "too large number" );
	}
	else
		throw std::invalid_argument( "not a number => " + value );
	
}

void	BitcoinExchange::printExchangedBitcoin( const std::string date, const std::string& value )
{
	double	rslt;
	std::stringstream	ss( value );
	ss >> rslt;
	
	std::map<std::string, double>::iterator	it = _bitcoinPrice.find( date );
	if (it == _bitcoinPrice.end())
	{
		it = _bitcoinPrice.lower_bound( date );
		if (it == _bitcoinPrice.begin())
			throw std::invalid_argument( "no valid date before => " + date );	
		--it;
	}
	rslt *= it->second;
	std::cout << std::fixed;
	std::cout.precision(2);
	cout << GREEN << date + " => " + value + " = " << rslt << DEF << std::endl;
}

bool	BitcoinExchange::isBissextile( const int& year )
{
	if ((year % 4 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 != 0 ))
		return false;
	return true;
}

bool	BitcoinExchange::isValidDate( const std::string& date )
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')		// check '-' position
		return false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i != 4 && i != 7 && (date[i] < '0' || date[i] > '9'))		// check if others positions are alls digit 
			return false;
	}
	std::string	years = date.substr( 0, 4 );
	std::string	month = date.substr( 5, 2 );
	std::string	day = date.substr( 8, 2 );
	int	y = atoi( years.c_str() );
	int	m = atoi( month.c_str() );
	int	d = atoi( day.c_str() );
	if (y >= 2009 && y < 2024 && m > 0 && d > 0)
	{	
		if (y == 2009 && m == 1 && d < 3)								// bitcoin network was created in 3/01/2009
			return false;
		else if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d <= 31)
			|| ((m == 4 || m == 6 || m == 9 || m == 11) && d <= 30)
			|| (m == 2 && isBissextile( y ) == 0 && d <= 28)
			|| (m == 2 && isBissextile( y ) == 1 && d <= 29))			// leap year(annee bissextile) had 366days (29days on february).
			return true;
	}
	return false;
}

bool	BitcoinExchange::isValidPrice( const std::string& price )
{
	if (price.find_first_not_of( "0123456789." ) != std::string::npos)
		return false;
	size_t	pointPosition = price.find_first_of('.');					// check if there is only 1 point.
	if (pointPosition != std::string::npos && pointPosition != price.find_last_of( '.' ))
		return false;
	std::stringstream	ss( price );									// check if price can be assigned to a double.
	ss >> _price;
	if (ss.fail())
		return false;
	return true;
}

