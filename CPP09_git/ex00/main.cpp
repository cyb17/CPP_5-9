/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:26:37 by yachen            #+#    #+#             */
/*   Updated: 2024/05/30 16:23:18 by yachen           ###   ########.fr       */
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
		BitcoinExchange	bitcoin( "./teste/data.csv", argv[1] );
		bitcoin.readDataFile();
		bitcoin.readInputFile();
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED << "Error: " << e.what() << std::endl << DEF;
	}
	return 0;
}