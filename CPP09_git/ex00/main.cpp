/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:26:37 by yachen            #+#    #+#             */
/*   Updated: 2024/05/29 18:19:36 by yachen           ###   ########.fr       */
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
		std::cerr << RED << "Invalid program parameter\n";
		exit(EXIT_FAILURE);
	}
	BitcoinExchange	bitcoin( "./teste/.csv", argv[1] );
	bitcoin.readDataFile();
	bitcoin.readInputFile();
	
	return 0;
}