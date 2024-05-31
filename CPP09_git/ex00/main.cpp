/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:26:37 by yachen            #+#    #+#             */
/*   Updated: 2024/05/31 12:59:53 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: invalid program parameter\n" << DEF;
		exit(EXIT_FAILURE);
	}
	try
	{
		BitcoinExchange	bitcoin( "teste/data.csv", argv[1] );
		bitcoin.exchangeBitcoin();
		
		// std::cout << "-------------------------------------\n";

		// BitcoinExchange	copy( bitcoin );
		// copy.exchangeBitcoin();

		// std::cout << "-------------------------------------\n";

		// BitcoinExchange	other( "teste/.csv", argv[1] );
		// other.exchangeBitcoin();
		
		// std::cout << "-------------------------------------\n";
		
		// other = bitcoin;
		// other.exchangeBitcoin();

	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << DEF;
	}
	return 0;
}