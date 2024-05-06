/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:40:30 by yachen            #+#    #+#             */
/*   Updated: 2024/05/06 15:05:45 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>


int	main( void )
{
	Data	data( 42, '*' );
	
	Data*	ptr = &data;
	std::cout << "int: " << ptr->getI() << "\nchar: " << ptr->getC() << '\n';
	std::cout << std::hex << ptr << '\n';
	
	uintptr_t*	raw = Serializer::serialize( ptr );
	std::cout << std::hex << raw << '\n' << std::dec;

	Data*	ptr2 = Serializer::deserialize( raw );
	std::cout << "int: " << ptr2->getI() << "\nchar: " << ptr2->getC() << '\n';
	
	return 0;
}