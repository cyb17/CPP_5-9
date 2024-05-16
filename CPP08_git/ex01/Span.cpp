/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:08:32 by yachen            #+#    #+#             */
/*   Updated: 2024/05/16 16:09:32 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "stdexcept"
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

Span::Span( unsigned int n ) : sizeMax( n ), shorted( 0 ), longest( 0 ) {}

Span::Span( const Span& other ) : sizeMax( other.sizeMax ), shorted( other.shorted ), longest( other.longest )
{
	std::deque<int>::const_iterator it;
	for (it = other.monSpan.begin(); it != other.monSpan.end(); it++)
		monSpan.push_back( *it );
}

Span&	Span::operator=( const Span& other )
{
	sizeMax = other.sizeMax;
	monSpan.clear();
	std::deque<int>::const_iterator it;
	for (it = other.monSpan.begin(); it != other.monSpan.end(); it++)
		monSpan.push_back( *it );
	return *this;
}

Span::~Span() {}

void	Span::addNumber( int const nb )
{
	if (monSpan.size() == sizeMax)
		throw std::out_of_range("the Span is full, can not add number anymore.");
	monSpan.push_back( nb );
	cout << GREEN << "number added successfully : " << nb << endl << RESET;
}

std::deque<int>	Span::getMonSpan() const
{
	return monSpan;
}

int	Span::shortedSpan()
{
	if (monSpan.empty())
		throw std::logic_error("the span is actually empty, can not calculate shorted distance.");
	else if (monSpan.size() == 1)
		throw std::logic_error("the span actual has just 1 element, can not calculate shorted distance.");
	std::deque<int>	sortedSpan( monSpan );
	std::sort( sortedSpan.begin(), sortedSpan.end() );
	std::deque<int>::const_iterator it = sortedSpan.begin();
	shorted = *(it + 1) - *it;
	for (; it != sortedSpan.end() - 1; ++it)
	{
		if (*(it + 1) - *it < shorted)
			shorted = *(it + 1) - *it;
	}
	// cout << "val : " << *it << "\tnext val : " << *it + 1 << "\tshorted : " << shorted;
	return shorted;
}

int	Span::longestSpan()
{
	if (monSpan.empty())
		throw std::logic_error("the span is actually empty, can not calculate longest distance.");
	else if (monSpan.size() == 1)
		throw std::logic_error("the span actual has just 1 element, can not calculate longest distance.");
	std::deque<int>	sortedSpan( monSpan );
	std::sort( sortedSpan.begin(), sortedSpan.end() );
	std::deque<int>::const_iterator it = sortedSpan.begin();
	longest = *(it + 1) - *it;
	for (; it != sortedSpan.end() - 1; ++it)
	{
		if (*(it + 1) - *it > longest)
			longest = *(it + 1) - *it;
	}
	return longest;
}

void	Span::addLotNumber( unsigned int n )
{
	for (unsigned int i = 0; i < n; i++)
	{
		srand(time(NULL) + i);
		addNumber(random() % 100);
	}		
}