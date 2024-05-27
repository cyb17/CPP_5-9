/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:12:47 by yachen            #+#    #+#             */
/*   Updated: 2024/05/27 10:56:41 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

using std::cout;
using std::endl;

int	 main()
{
	int	val = 42;
	int	arr[] = {54, 354, 54, 65, 76, 42};
	cout << YELLOW << "--------------------------------------\n" << RESET;
	cout << "Find first occurrence of : " << BLUE << val << RESET << "\n\n";
	
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << YELLOW << "=> " << RESET << "Test: create a Vector with values : ";
	printContainerValue( v );
	try
	{
		cout << "Use easyFind : " << BLUE << *easyFind( v, val )  << " : Occurrence found\n" << endl << RESET;
	}
	catch(const std::invalid_argument& e)
	{
		cout << RED << "Error: " << e.what() << RESET << endl;
	}
	
	std::list<int> l(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << YELLOW << "=> " << RESET << "Test: create a List with values : ";
	printContainerValue( l );
	try
	{
		cout << "Use easyFind : " << BLUE << *easyFind( l, val )  << " : Occurrence found\n" << endl << RESET;
	}
	catch(const std::invalid_argument& e)
	{
		cout << RED << "Error: " << e.what() << RESET << endl;
	}
	
	std::deque<int> d(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << YELLOW << "=> " << RESET << "Test: create a Deque with values : ";
	printContainerValue( d );
	try
	{
		cout << "Use easyFind : " << BLUE << *easyFind( d, val )  << " : Occurrence found\n" << endl << RESET;
	}
	catch(const std::invalid_argument& e)
	{
		cout << RED << "Error: " << e.what() << RESET << endl;
	}
	
	return 0;
}