/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:07 by yachen            #+#    #+#             */
/*   Updated: 2024/06/07 17:28:20 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <string>
#include <cstdlib>
#include <algorithm>
using std::cout;

PmergeMe::PmergeMe( char** sequence ) : _unpaired( -1 ), _sequence( sequence )
{
	parseSequence();
}

PmergeMe::PmergeMe( const PmergeMe& other )
{
	_sequence = other._sequence;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=( const PmergeMe& other )
{
	if (this != &other)
		_sequence = other._sequence;
	return *this;
}

void	PmergeMe::parseSequence()
{
	int	k = -1;
	while (_sequence[++k])
	{
		std::string	nbStr( _sequence[k] );
		if (nbStr.empty())
			throw std::invalid_argument( " nb can not be a NULL string" );
        if (nbStr.find_first_not_of( " \t" ) == std::string::npos)
            throw std::invalid_argument( "nb can not be an empty string" );
		size_t start = nbStr.find_first_not_of( " \t" );
        
		if (start == std::string::npos)
            throw std::invalid_argument( "nb can not be an empty string" );
        size_t end = nbStr.find_last_not_of( " \t" );
        nbStr = nbStr.substr( start, end - start + 1 );

        for (size_t i = 0; i < nbStr.size(); ++i)
		{
            if (!std::isdigit( nbStr[i]) )
                throw std::invalid_argument( "nb must be a positive integer: " + nbStr );
        }
		long number = std::atol( nbStr.c_str() );
        if (number < 0 || (number == 0 && nbStr != "0") || number > std::numeric_limits<int>::max())
            throw std::invalid_argument( "nb must be a positive integer: " + nbStr );
        _unsortedList.push_back( static_cast<int>( number ) );
	}
}

// Make list of pair nb : first = max | second = min, _unpaired = unpaired nb if exist. 
void	PmergeMe::findMaxMakePairlist()
{
	std::vector<int>::iterator	it = _unsortedList.begin();
	std::vector<int>::iterator	end = _unsortedList.end();
	if ( _unsortedList.size() % 2 != 0 )
	{
		end = _unsortedList.end() - 1;
		_unpaired = *end;
	}
	for (; it != end; it+=2)
	{
		std::pair<int, int> pair = std::make_pair( *it, *(it + 1) );
		if (pair.first < pair.second)
			std::swap( pair.first, pair.second );
		_pair.push_back( pair );
	}
}

void	PmergeMe::merge( const int left, const int mid, const int right )
{
	int	leftSize = mid - left + 1;
	int	rightSize = right - mid;
	std::vector<std::pair<int, int> >	leftArr;
	std::vector<std::pair<int, int> >	rightArr;
	for (int i = 0; i < leftSize; i++)
		leftArr.push_back(_pair[left + i]);
	for (int i = 0; i < rightSize; i++)
		rightArr.push_back(_pair[mid + 1 + i]);
	
	int	i = 0, j = 0, k = left;
	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i].first <= rightArr[j].first)
			_pair[k++] = leftArr[i++];
		else
			_pair[k++] = rightArr[j++];
	}
	
	while (i < leftSize)
    		_pair[k++] = leftArr[i++];
    while (j < rightSize)
			_pair[k++] = rightArr[j++];
}

// Sort pair->first(max) in ascending order.
void	PmergeMe::mergeSort( const int begin, const int end )
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSort( begin, mid );
	mergeSort( mid + 1, end );
	merge( begin, mid, end );
}

std::vector<int>	PmergeMe::vectorInsertSort()
{
	std::vector<int>	sorted;
	std::vector<int>	unsorted;
	if (_unpaired != -1)
		unsorted.push_back( _unpaired );
	sorted.push_back( _pair[0].second );
	for (size_t i = 0, j = 1; i < _pair.size() && j < _pair.size(); i++, j++)
	{
		sorted.push_back( _pair[i].first );
		unsorted.push_back( _pair[j].second );
	}
	std::vector<int>::iterator	end;
	for (size_t i = 0; i < unsorted.size(); i++)
	{
		end = std::upper_bound( sorted.begin(), sorted.end(), unsorted[i] );
		sorted.insert( end, unsorted[i] );
	}
	return sorted;
}

std::list<int>	PmergeMe::listInsertSort()
{
	std::list<int>	sorted;
	std::list<int>	unsorted;
	if (_unpaired != -1)
		unsorted.push_back( _unpaired );
	sorted.push_back( _pair[0].second );
	for (size_t i = 0, j = 1; i < _pair.size() && j < _pair.size(); i++, j++)
	{
		sorted.push_back( _pair[i].first );
		unsorted.push_back( _pair[j].second );
	}
	std::list<int>::iterator	end;
	std::list<int>::iterator	it = unsorted.begin();
	for (; it != unsorted.end(); ++it)
	{
		end = std::upper_bound( sorted.begin(), sorted.end(), *it );
		sorted.insert( end, *it );
	}
	return sorted;
}

