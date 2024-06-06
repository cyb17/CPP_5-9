/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:35:56 by yachen            #+#    #+#             */
/*   Updated: 2024/06/06 13:43:29 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
			
			// merge.pushToVector();
			merge.findMaxMakePairlist();
			merge.mergeSort( 0, 6 );
			merge.printMergeInfo();
		}
		catch ( const std::invalid_argument& e )
		{
			std::cerr << RED << "Error: " << e.what() << std::endl << DEF;
		}
	
	}
	return 0;
}