/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:59:59 by yachen            #+#    #+#             */
/*   Updated: 2024/05/24 12:47:31 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#define DEF "\e[0m"
#define BLUE "\e[34m"
#define RED "\e[31m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

class	BitcoinExchange
{
	private:
	
		std::map<int, std::string>		_fileContent;
		std::map<std::string, float>	_bitcoinPrice;

	public:

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange();

		BitcoinExchange&	operator=( const BitcoinExchange& other );

		void	readFile();
		void	analyzeFileContent();
};

#endif