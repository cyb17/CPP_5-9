/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:35:56 by yachen            #+#    #+#             */
/*   Updated: 2024/06/09 17:56:34 by yachen           ###   ########.fr       */
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
			PmergeMe	merge( argv + 1 );
			
			std::clock_t	vExeTime = clock();
			std::vector<int>	v = merge.vectorMergeInsertSort();
			vExeTime = clock() - vExeTime;

			std::clock_t	lExeTime = clock();
			merge.listMergeInsertSort();
			vExeTime = clock() - lExeTime;
			
			merge.printProgramInfo( v );
			std::cout << std::fixed << std::setprecision( 5 );
			std::cout << "time to process a range of " << argc - 1 << " elements with std::vector : "\
			<< vExeTime << " clicks of CPU | " << static_cast<float>(vExeTime) / CLOCKS_PER_SEC << "us" << '\n';
			std::cout << "time to process a range of " << argc - 1 << " elements with std::list : "\
			<< lExeTime << " clicks of CPU | " << static_cast<float>(lExeTime) / CLOCKS_PER_SEC << "us" << '\n';
		}
		catch ( const std::invalid_argument& e )
		{
			std::cerr << RED << "Error: " << e.what() << std::endl << DEF;
		}
	
	}
	return 0;
}