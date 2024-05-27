/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:44:04 by yachen            #+#    #+#             */
/*   Updated: 2024/05/27 11:00:48 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#define RESET "\e[0m"
#define BLUE "\e[34m"
#define RED "\e[31m"
#define YELLOW "\e[33m"

template<typename T> void	printContainerValue( T& container )
{
	for(typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << BLUE << *it << ' ';
	std::cout << '\n' << RESET;
}

template<typename T> typename T::iterator	easyFind( T& container, int val )
{
	typename T::iterator it = find( container.begin(), container.end(), val );
	if (it != container.end())
		return it;
	else
		throw std::invalid_argument("Occurence not found");
}

#endif