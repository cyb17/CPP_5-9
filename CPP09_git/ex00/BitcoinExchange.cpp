/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:39:46 by yachen            #+#    #+#             */
/*   Updated: 2024/05/21 18:04:15 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>

BitcoinExchange::BitcoinExchange()
{
	fillBitcoinPrice();
}

void	fillBitcoinPrice()
{
	
	
}

void	BitcoinExchange::readDataFile()
{
	std::ifstream	ifs("./data.csv");

	ifs.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	if (!ifs.is_open())
	{
		std::cerr << RED << "open csv data file failed\n" << RESET;
		exit(EXIT_FAILURE);
	}
	try
	{
		
	}
	
}