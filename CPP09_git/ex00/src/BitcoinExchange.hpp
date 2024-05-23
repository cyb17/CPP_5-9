/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:16:42 by yachen            #+#    #+#             */
/*   Updated: 2024/05/23 17:23:55 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#define RESET "\e[0m"
#define BLUE "\e[34m"
#define RED "\e[31m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"
#include <map>
#include <string>

class	BitcoinExchange
{
	private:
		
		std::map<std::string, float>	bitcoinPrice;

	public:

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange& other );
		~BitcoinExchange();

		BitcoinExchange&	operator=( const BitcoinExchange& other );
		
		void	readDataFile();
		
};

#endif