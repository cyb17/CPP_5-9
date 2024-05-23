#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "src/BitcoinExchange.hpp"

int	checkDataSyntaxe( std::ifstream& ifsr )
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

	return 0;
}

void	readDataFile()
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
		checkDataSyntaxe( ifs );
	}
	catch(const std::ios_base::failure& e)
	{
		ifs.close();
		std::cout << RED << e.what() << '\n' << RESET;
		exit(EXIT_FAILURE);
	}
}

int	main()
{
	readDataFile();

	return 0;
}