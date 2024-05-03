/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:40:30 by yachen            #+#    #+#             */
/*   Updated: 2024/05/03 12:06:41 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>


int	main( void )
{
	Data	data( 42, '*' );
	Data*	ptr = &data;
	uintptr_t*	raw = Serializer::serialize( ptr );

	std::cout << "int: " << raw->getI() << "\nchar: " << rwa;

	Data*	ptr2 = Serializer::deserialize( raw );
	
	std::cout << ptr2->getI() << '\n';
	
	return 0;
}