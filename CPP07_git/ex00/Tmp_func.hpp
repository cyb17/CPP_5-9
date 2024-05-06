/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_func.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:52:11 by yachen            #+#    #+#             */
/*   Updated: 2024/05/06 17:47:10 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TMP_FUNC_HPP
#define TMP_FUNC_HPP

#include <iostream>

template<typename T>
void	swap( T& a, T& b )
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const	T& max( const T& a, const T& b )
{
	if (a == b)
		return b;
	return a > b ? a : b;
}

template<typename T>
const	T& min( const T& a, const T& b )
{
	if (a == b)
		return b;
	return a < b ? a : b;
}

#endif