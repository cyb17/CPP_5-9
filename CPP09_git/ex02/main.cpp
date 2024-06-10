/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:35:56 by yachen            #+#    #+#             */
/*   Updated: 2024/06/10 11:56:18 by yachen           ###   ########.fr       */
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
			std::cout << "time to process a range of " << GREEN << argc - 1  << DEF\
			<< " elements with" << GREEN << " std::vector" << DEF << " : "\
			<< GREEN << vExeTime << " clicks of CPU" << DEF << " | " << GREEN << static_cast<float>(vExeTime) / CLOCKS_PER_SEC << " us" << '\n' << DEF;
			std::cout << "time to process a range of " << GREEN <<  argc - 1 << DEF\
			<<" elements with" << GREEN << " std::list" << DEF << " : "\
			<< GREEN << lExeTime << " clicks of CPU" << DEF << " | " << GREEN <<  static_cast<float>(lExeTime) / CLOCKS_PER_SEC << " us" << "\n\n" << DEF;
		}
		catch ( const std::invalid_argument& e )
		{
			std::cerr << RED << "Error: " << e.what() << std::endl << DEF;
			return 1;
		}
	
	}
	return 0;
}