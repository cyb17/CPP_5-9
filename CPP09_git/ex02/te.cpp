#include <iostream>
#include <cstdlib>
#include <utility>

int	main( int argc, char** argv)
{
	std::pair<int, int>	pair;

	pair = std::make_pair(1, 2);

	std::cout << pair.first << '|' <<  pair.second << std::endl;
	return 0;
}