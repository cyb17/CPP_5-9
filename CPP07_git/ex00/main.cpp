/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:04:19 by yachen            #+#    #+#             */
/*   Updated: 2024/05/06 17:52:40 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Tmp_func.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}

// int	main( void )
// {
// 	int	a = 15;
// 	int	b = 25;

// 	std::cout << "Value before swap:\n" <<  "a = " << a << " | b = " << b << std::endl;
// 	swap<int>(a, b);
// 	std::cout << "Value after swap:\n" <<  "a = " << a << " | b = " << b << std::endl;

// 	std::cout << "Max between a and b :" << max<int>(a, b) << std::endl;
// 	std::cout << "Min between a and b :" << min<int>(a, b) << std::endl;
	
// 	return 0;
// }