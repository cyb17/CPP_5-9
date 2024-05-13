/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:40:30 by yachen            #+#    #+#             */
/*   Updated: 2024/05/13 15:23:41 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>


int	main( void )
{
	std::cout << "Create an objet of Data class\n";
	Data	data( 42, '*' );
	
	std::cout << "Assign it to a Data* ptr\n";
	Data*	ptr = &data;
	std::cout << "Print data's values and Data* ptr's adress :\n";
	std::cout << GREEN << "int: " << ptr->getI() << "\nchar: " << ptr->getC() << '\n';
	std::cout << GREEN << std::hex << ptr << '\n' <<  RESET;

	std::cout << "Serialize Data* ptr to uintptr_t* raw\n";
	uintptr_t*	raw = Serializer::serialize( ptr );
	std::cout << "Print raw'adress\n";
	std::cout << GREEN << std::hex << raw << '\n' << std::dec << RESET;

	std::cout << "Deserialize raw to Data* ptr2\n";
	Data*	ptr2 = Serializer::deserialize( raw );
	std::cout << "Print ptr2's values\n";
	std::cout << GREEN << "int: " << ptr2->getI() << "\nchar: " << ptr2->getC() << '\n' << RESET;
	
	return 0;
}