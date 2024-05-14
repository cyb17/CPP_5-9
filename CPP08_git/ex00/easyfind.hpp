/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:44:04 by yachen            #+#    #+#             */
/*   Updated: 2024/05/14 18:54:29 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <algorithm>
#include <iostream>
#define RESET "\e[0m"
#define BLUE "\e[34m"

template<typename T> void	printContainerValue( T container )
{
	for(typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << BLUE << *it << ' ';
	std::cout << '\n' << RESET;
}

template<typename T> int	easyfind( T container, int val )
{
	typename T::iterator it = find( container.begin(), container.end(), val );
	if (it != container.end())
		return "occurence found";
	return "occurence not found";
}

#endif