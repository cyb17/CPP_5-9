/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:33:03 by yachen            #+#    #+#             */
/*   Updated: 2024/05/16 18:25:25 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T, typename F>
void	iter( T* array, int len, F f)
{
	for(int	i = 0; i < len; i++)
		f(array[i]);
	std::cout << '\n';
}

template<typename T>
void	print( T& value )
{
	std::cout << value << ' ';
}

#endif