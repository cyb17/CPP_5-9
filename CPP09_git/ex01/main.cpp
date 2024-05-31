/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:14:11 by yachen            #+#    #+#             */
/*   Updated: 2024/05/31 13:32:05 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcep>

int	main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << RED << "Error : program's argument not valid\n" << DEF;
		return 1;
	}
	
	RPN	rpn();
	try
	{
		std::cout << BLUE << rpn.calculateResult( argv[1] ) << std::endl << DEF;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED << "Error : " << e.what() << std::endl << DEF;
		return 1;
	}
	return 0;
}