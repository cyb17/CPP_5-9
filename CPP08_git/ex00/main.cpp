/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:12:47 by yachen            #+#    #+#             */
/*   Updated: 2024/05/14 18:53:06 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
// sequence containers
#include <vector>
#include <list>
#include <deque>
// container adapters: provide a different interface for sequential containers
#include <queue>
#include <stack> 

using std::cout;
using std::endl;

int	 main()
{
	int	val = 42;
	int	arr[] = {54, 354, 54, 65, 76, 42};
	cout << "Value to find a occurence : " << BLUE << val << RESET << "\n\n";
	
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	cout << "Test: create Vector with values : ";
	printContainerValue( v );
	cout << "Use easyfind : " << BLUE << easyfind( v, val ) << endl << RESET;
	
	return 0;
}