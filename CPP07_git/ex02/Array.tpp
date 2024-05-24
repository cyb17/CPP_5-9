/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:45:07 by yachen            #+#    #+#             */
/*   Updated: 2024/05/24 18:09:48 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <stdexcept>

using std::cout;
using std::endl;

template<typename T>
Array<T>::Array()
{
	element = NULL;
	arraySize = 0;
	cout << "Default constructor called\n";
}

template<typename T>
Array<T>::Array( unsigned int n )
{
	arraySize = n;
	element = new T[arraySize];
	for(unsigned int i = 0; i < n; i++)
		element[i] = 0;
	cout << "Unsigned int constructor called\n";
}

template<typename T>
Array<T>::Array( const Array<T>& other )
{
	this->arraySize =  other.size();
	this->element = new  T[this->arraySize];
	for (size_t i = 0; i < this->arraySize; i++)
		this->element[i] = other[i];
	cout << "Copy constructor called\n";
}

template<typename T>
Array<T>&	Array<T>::operator= ( const Array<T>& other )
{
	if (this != &other)
	{
		this->arraySize = other.size();
		delete[] this->element;
		this->element = new T[this->arraySize];
		for (size_t i = 0; i < this->arraySize; i++)
			this->element[i] = other[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] element;
	cout << "Default destructor called\n";
}

template<typename T>
T&	Array<T>::operator[] (unsigned int i)
{
	if (i >= arraySize)
		throw std::out_of_range("The provided indice is out of range");
	return element[i];
}

template<typename T>
const T&	Array<T>::operator[] (unsigned int i) const
{
	if (i >= arraySize)
		throw std::out_of_range("The provided indice is out of range");
	return element[i];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return this->arraySize;
}
