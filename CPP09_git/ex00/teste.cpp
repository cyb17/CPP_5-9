#include <fstream>
#include <iostream>
#include <string>

int	main()
{
	std::ifstream	file("./BitcoinExchange.hpp");
	// file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
	// try
	// {
	// 	file.open( "../../../Downloads/cpp_09/file", std::ifstream::in );
	// 	// if (!file.is_open())
	// 		// throw failure("open file failed");
		std::string s;
		file.getline(s, 256);
		std::cout << s << '\n';
		file.close();
	// }
	// catch (const std::ios_base::failure& e)
	// {
	// 	std::cout << e.what() << '\n';
	// 	return EXIT_FAILURE;
	// }
	return 0;
}