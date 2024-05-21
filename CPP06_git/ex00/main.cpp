/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 09:53:27 by yachen            #+#    #+#             */
/*   Updated: 2024/05/21 17:14:12 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc > 2)
		std::cout << RED << "You can only convert ONE string at time\n" << RESET;
	else if (!argv[1])
		std::cout << RED << "Cannot convert an NULL string.\n" << RESET;
	else if (isEmpty( argv[1] ))
		std::cout << RED << "Cannot convert an EMPTY string.\n" << RESET;
	else
	{
		std::string str( strWithoutWhitespace( argv[1] ) );
		ScalarConverter::convert( str );
	}
	return 0;
}


// #!/bin/bash

// # Liste des entrées de test
// tests=(
//     ""
//     "   "
//     "abcdfgdhj"
//     "fgjsdh678"
//     "^&*(*"
//     "78.54gf"
//     "a"
//     "*"
//     "8"
//     "42"
// 	"33"
// 	"67"
//     "2147483647"
//     "-2147483649"
//     "0f"
//     "789.54f"
//     "7895437.543"
//		"43.0f";
//		"42.789"
// )

// # Exécuter le programme Convert pour chaque entrée de test
// for input in "${tests[@]}"; do
//     echo "Input: \"$input\""
//     ./Convert "$input"
//     echo "------------------"
// done