/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:35:56 by yachen            #+#    #+#             */
/*   Updated: 2024/06/08 12:54:56 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

int	main( int argc, char** argv )
{
	if (argc < 2)
	{
		std::cerr << RED << "Error: number of argument not valid" << DEF << std::endl;
		return 1;	
	}
	else
	{
		try
		{
			std::clock_t	t = clock();
			PmergeMe	merge( argv + 1 );
			std::vector<int>	v = merge.vectorMergeInsertSort();
			merge.printProgramInfo( v );
			t = clock() - t;
			std::cout << std::fixed << std::setprecision( 5 );
			std::cout << "time : " << t << " clicks of CPU | " << static_cast<float>(t) / CLOCKS_PER_SEC << "ms" << '\n';
}
		catch ( const std::invalid_argument& e )
		{
			std::cerr << RED << "Error: " << e.what() << std::endl << DEF;
		}
	
	}
	return 0;
}