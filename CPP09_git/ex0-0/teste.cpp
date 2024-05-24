#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>
#include "src/BitcoinExchange.hpp"

int	checkDataSyntaxe( std::ifstream& ifsr )
{
	int	year;
	int	month;
	int	day;
	int	price;
	std::string	line;

	while (std::getline( ifsr, line ))
	{
		std::cout << line << '\n';
		line.getline(year, '-');
		line.getline(month, '-');
		line.getline(day, ',');
		line.getline(day);
		line.clear();
	}

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