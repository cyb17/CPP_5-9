/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:33:42 by yachen            #+#    #+#             */
/*   Updated: 2024/05/07 17:29:05 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
using std::cout;

int	main( void )
{

	Array<int>	arr1;
	cout << arr1.size() << '\n';	
	
	Array<int>	arr2( 6 );
	cout << arr2.size() << '\n';
	cout << arr2.getElement( 5 ) << '\n';

	int*	a = new int(7);
	cout << *a << '\n';

	return 0;
}  