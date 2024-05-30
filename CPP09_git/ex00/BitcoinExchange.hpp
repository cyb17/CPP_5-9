/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:59:59 by yachen            #+#    #+#             */
/*   Updated: 2024/05/30 17:17:06 by yachen           ###   ########.fr       */
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

		bool	openFiles();
		bool	isValidDate( const std::string& date );
		bool	isValidPrice( const std::string& price );
		bool	isBissextile( const int& year );
		void	checkValue( const std::string& value );
		bool	isValidDataFilePath( const char*& priceFilePath );
		void	printExchangedBitcoin( const std::string date, const std::string& value );
		
	public:

		BitcoinExchange( const char* priceFilePath, const char* inputFilePath );
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange();

		BitcoinExchange&	operator=( const BitcoinExchange& other );
		
		void	readDataFile();
		void	readInputFile();
};

#endif