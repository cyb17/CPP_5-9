/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:59:59 by yachen            #+#    #+#             */
/*   Updated: 2024/05/29 18:12:18 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#define DEF "\e[0m"
#define BLUE "\e[34m"
#define RED "\e[31m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

class	BitcoinExchange
{
	private:
	
		double							_price;
		const char*						_priceFilePath;
		const char*						_inputFilePath;
		std::ifstream					_priceFile;
		std::ifstream					_inputFile;
		std::map<std::string, double>	_bitcoinPrice;

		void	openFiles();
		bool	isValidDate( std::string& date );
		bool	isValidPrice( std::string& price );
		void	exitProgram( const std::string errMsg );
		void	checkValue( std::string& value );
		void	checkDataFilePath( const char*& priceFilePath );
		
	public:

		BitcoinExchange( const char* priceFilePath, const char* inputFilePath );
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange();

		BitcoinExchange&	operator=( const BitcoinExchange& other );
		
		void	readDataFile();
		void	readInputFile();

		// void	exchangeBitcoin();
};

#endif