/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:39:46 by yachen            #+#    #+#             */
/*   Updated: 2024/05/23 17:23:04 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <stdlib>


int	BitcoinExchange::checkDataSyntaxe( std::ifstream& ifsr )
{
	std::string	year;
	std::string	month;
	std::string	day;
	std::string	price;
	std::getline(ifsr, year, '-');
	std::getline(ifsr, month, '-');
	std::getline(ifsr, day, ',');
	std::getline(ifsr, price);
	std::cout << year + month + day + price << "\n";
}

void	BitcoinExchange::readDataFile()
{
	std::ifstream	ifs("../data.csv");

	ifs.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	if (!ifs.is_open())
	{
		std::cerr << RED << "open csv data file failed\n" << RESET;
		exit(EXIT_FAILURE);
	}
	try
	{
		checkDataSyntaxe( ifs );
	}
	catch(const std::ios_base::failure& e)
	{
		ifs.close();
		std::cout << RED << e.what() << '\n' << RESET;
		exit(EXIT_FAILURE);
	}
}