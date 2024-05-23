/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:33:42 by yachen            #+#    #+#             */
/*   Updated: 2024/05/23 15:26:24 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
using std::cout;

int	main( void )
{
	cout << BLUE << "Creating empty arr1\n" << RESET;
	Array<int>	arr1;
	try
	{
		cout << BLUE << "value of arr1[0]: " << arr1[0] << '\n' << RESET;
	}
	catch (const std::out_of_range& e)
	{
		cout << RED << "error of out of range\n" << RESET;
	}
	cout << BLUE << "arr1's size : " << arr1.size() << "\n\n"<< RESET;
	

	cout << BLUE << "Creating arr2 size n, initialized by default\n" << RESET;
	size_t	n = 6;
	cout << BLUE << "n : " << n << '\n' << RESET;
	Array<int>	arr2( n );
	cout << BLUE << "arr2's values : \n" << RESET;
	for (size_t i = 0; i < n; i++)
		cout << BLUE << arr2[i] <<  '\t';
	cout << "\n" << RESET;
	cout << BLUE << "arr2's size : " << arr2.size() << "\n\n"<< RESET;
	
	
	cout << BLUE << "Try to display arr2[10] :\n" << RESET;
	try
	{
		cout <<	arr2[10] << '\n';
	}
	catch (const std::out_of_range& e)
	{
		cout << RED << "error of out of range\n\n" << RESET;
	}
	
	cout << BLUE << "Copy arr2 to arr4 : \n" << RESET;
	Array<int> arr4 (arr2);
	cout << BLUE << "arr2's adress : "<< &arr2 << '\n';
	cout << "arr4's adress : " << &arr4 << "\n\n" << RESET;
	
	cout << BLUE << "Assign arr1 to arr4 : \n" << RESET;
	arr4 = arr1;
	cout << BLUE << "arr1's adress : "<< &arr1 << '\n';
	cout << "arr4's adress : " << &arr4 << "\n" << RESET;
	
	return 0;
}