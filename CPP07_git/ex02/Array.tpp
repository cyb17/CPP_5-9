/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:45:07 by yachen            #+#    #+#             */
/*   Updated: 2024/05/07 14:06:43 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

using std::cout;
using std::endl;

template<typename T>
Array<T>::Array()
{
	element = NULL;
	arraySize = 0;
	cout << BLUE << "Default constructor called\n" << RESET;
}

template<typename T>
Array<T>::Array( unsigned int n )
{
	arraySize = n;
	element = new T[arraySize];
	for (int i = 0; i < this->arraySize; i++)
		this->element[i] = 0 ;
	cout << BLUE << "Unsigned int constructor called\n" << RESET;
}

template<typename T>
Array<T>::Array( const Array<T>& other )
{
	this->arraySize =  other.size();
	this->element = new  T[this->arraySize];
	for (int i = 0; i < this->arraySize; i++)
		this->element[i] = (other.getElement())[i];
	cout << BLUE << "Copy constructor called\n" << RESET;
}

template<typename T>
Array<T>&	Array<T>::operator= ( const Array<T>& other )
{
	if (this != &other)
	{
		this->arraySize = other.size();
		delete[] this->element;
		this->element = new T[this->arraySize];
		for (int i = 0; i < this->arraySize; i++)
			this->element[i] = (other.getElement())[i];
	}
	return *this;
}

template<typename T>
Array<T>::~Array()
{
	delete[] element;
	cout << MAGENTA << "Default destructor called\n" << RESET;
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return this->arraySize;
}

template<typename T>
T*	Array<T>::getElement() const
{
	return element;
}