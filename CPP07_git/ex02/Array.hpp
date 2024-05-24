/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:55:15 by yachen            #+#    #+#             */
/*   Updated: 2024/05/24 18:09:39 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define RED "\e[31m"
#define RESET "\e[0m"

template<typename T>
class	Array
{
	private:
	
		T* element;
		unsigned int	arraySize;
	
	public:
	
		Array();
		Array( unsigned int n );
		Array( const Array<T>& other );
		Array&	operator= ( const Array<T>& other );
		~Array();

		T&	operator[] ( unsigned int i );
		const T&	operator[] ( unsigned int i ) const;

		unsigned int	size() const;
};

#include "Array.tpp"

#endif