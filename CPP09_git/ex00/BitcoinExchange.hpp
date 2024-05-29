/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:59:59 by yachen            #+#    #+#             */
/*   Updated: 2024/05/29 13:02:12 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#define DEF "\e[0m"
#define BLUE "\e[34m"
#define RED "\e[31m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

class	BitcoinExchange
{
	private:
	
		std::string						_path;
		std::ifstream					_dataFile;
		std::map<std::string, double>	_bitcoinPrice;
		// std::ifstream					_inputFile;
		double							_price;

		
	public:

		BitcoinExchange( const std::string path );
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange();

		BitcoinExchange&	operator=( const BitcoinExchange& other );

		void	readDataFile();
		void	exitProgram( const char* errMsg );
		bool	isValidPath();
		bool	isValidDate( std::string date );
		bool	isValidPrice( std::string price );
		
		bool	isValidValue( std::string& value );
		void	exchangeBitcoin();
};

#endif