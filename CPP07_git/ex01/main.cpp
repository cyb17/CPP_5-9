/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:46:55 by yachen            #+#    #+#             */
/*   Updated: 2024/05/16 18:45:07 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <string>

int	main( void )
{
	int Arr1[5] = {1, 2, 3, 4, 5};
	::iter<int>(Arr1, 5, print<const int>);

	char Arr2[5] = {'a', 'b','c', 'd', 'e'};
	::iter<char>(Arr2, 5, print<char>);

	std::string Arr3[5] = {"il", "fait", "beau", "aujourd'", "hui"};
	::iter<std::string>(Arr3, 5, print<std::string>);

	float Arr4[5] = {1.2, 2.2, 3.2, 4.2, 5.2};
	::iter<float>(Arr4, 5, print<float>);

	return 0;	
}