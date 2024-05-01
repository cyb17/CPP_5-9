/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:53:27 by yachen            #+#    #+#             */
/*   Updated: 2024/05/01 11:20:40 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iterator>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc > 2)
		std::cout << RED << "You can only convert ONE string at time\n" << RESET;
	else if (!argv[1])
		std::cout << RED << "String to convert can't be NULL\n" << RESET;
	else if (IsEmpty( argv[1] ))
		std::cout << RED << "String to convert can't be EMPTY\n" << RESET;
	else
	{
		std::string str( StrWithoutWhitespace( argv[1] ) );
		ScalarConverter::Convert( str );
	}
	return 0;
}


// inputs : 

// null string
// abcdfgdhj
// fgjsdh678
// ^&*(*)
// 46738
// 0.0f
// 0.0
// space
// space42

// literal type:

// string -> impossible 
// nb : 32-126 (char displayable)
