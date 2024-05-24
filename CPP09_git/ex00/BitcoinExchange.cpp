/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:06:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/24 13:33:09 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iterator>
using std::cout;

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other ) : _bitcoinPrice( other._bitcoinPrice ) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator= ( const BitcoinExchange& other )
{
	if (this != &other )
		_bitcoinPrice = other._bitcoinPrice;
	return *this;
}

void	BitcoinExchange::readFile()
{
	std::ifstream	ifs( "./data.csv" );
	if (!ifs.is_open())
	{
		std::cerr << RED << "Open _bitcoinPrice file failed\n" << DEF;
		exit(EXIT_FAILURE);
	}
	std::string					line;
	int							i = 0;
	while (std::getline(ifs, line))
	{
		_fileContent[i++] = line;
		line.clear();
	}
	// std::map<int, std::string>::iterator	it = _fileContent.begin();
	// for (; it != _fileContent.end(); it++)
		// cout << "value:" << it->second <<'\n';
	// cout << "getline failed : "<< std::getline(ifs, line) << '\n';
	ifs.close();
}

void	BitcoinExchange::analyzeFileContent()
{
	std::map<int, std::string>::iterator	it = _fileContent.begin();
	for (; it != _fileContent.end(); it++)
		cout << "value:" << it->second <<'\n';

}