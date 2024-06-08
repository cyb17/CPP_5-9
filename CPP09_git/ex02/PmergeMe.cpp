/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:07 by yachen            #+#    #+#             */
/*   Updated: 2024/06/08 11:49:37 by yachen           ###   ########.fr       */
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

void	PmergeMe::merge( std::vector<std::pair<int, int> >& pair, const int left, const int mid, const int right )
{
				// split pair to 2 list : left nb and right nb.
	int	leftSize = mid - left + 1;
	int	rightSize = right - mid;
	std::vector<std::pair<int, int> >	leftArr;
	std::vector<std::pair<int, int> >	rightArr;
	for (int i = 0; i < leftSize; i++)
		leftArr.push_back(pair[left + i]);
	for (int i = 0; i < rightSize; i++)
		rightArr.push_back(pair[mid + 1 + i]);
				// compare the max of each pair to make pair sorted.
	int	i = 0, j = 0, k = left;
	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i].first <= rightArr[j].first)
			pair[k++] = leftArr[i++];
		else
			pair[k++] = rightArr[j++];
	}
				// add the rest tp pair.
	while (i < leftSize)
    		pair[k++] = leftArr[i++];
    while (j < rightSize)
			pair[k++] = rightArr[j++];
}

// make pair list sorted with :pair->first = max, in ascending order.
void	PmergeMe::mergeSort( std::vector<std::pair<int, int> >& pair, const int begin, const int end )
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSort(pair, begin, mid );
	mergeSort(pair, mid + 1, end );
	merge(pair, begin, mid, end );
}

void	PmergeMe::vectorInsertSort( std::vector<int>& sorted, std::vector<std::pair<int, int> >& pair )
{
	std::vector<int>	unsorted;
	if (_unpaired != -1)
		unsorted.push_back( _unpaired );
	sorted.push_back( pair[0].second );
	for (size_t i = 0; i < pair.size(); i++)
		sorted.push_back( pair[i].first );
	for (size_t i = 1; i < pair.size(); i++)
		unsorted.push_back( pair[i].second );
	std::vector<int>::iterator	end;
	for (size_t i = 0; i < unsorted.size(); i++)
	{
		end = std::upper_bound( sorted.begin(), sorted.end(), unsorted[i] );
		sorted.insert( end, unsorted[i] );
	}
}

std::vector<int>	PmergeMe::vectorMergeInsertSort()
{
	if (_unsortedList.size() == 1)
		return _unsortedList;
	else if (_unsortedList.size() == 2)
	{
		if (_unsortedList[0] > _unsortedList[1])
			std::swap( _unsortedList[0], _unsortedList[1] );
		return _unsortedList;
	}
	std::vector<int>	sortedList;
	std::vector<std::pair<int, int> >	pair = makePairlist<std::vector<std::pair<int,int> > >();
	mergeSort(pair, 0, pair.size() - 1 );
	vectorInsertSort( sortedList, pair);
	return sortedList;
}

void	PmergeMe::printProgramInfo( const std::vector<int>& v )
{
	std::cout << "Before: ";
	printContainer<std::vector<int> >( _unsortedList );
	std::cout << "After: ";
	printContainer<std::vector<int> >( v );
}

// std::list<int>	PmergeMe::listInsertSort()
// {
// 	std::list<int>	sorted;
// 	std::list<int>	unsorted;
// 	if (_unpaired != -1)
// 		unsorted.push_back( _unpaired );
// 	sorted.push_back( _pair[0].second );
// 	for (size_t i = 0, j = 1; i < _pair.size() && j < _pair.size(); i++, j++)
// 	{
// 		sorted.push_back( _pair[i].first );
// 		unsorted.push_back( _pair[j].second );
// 	}
// 	std::list<int>::iterator	end;
// 	std::list<int>::iterator	it = unsorted.begin();
// 	for (; it != unsorted.end(); ++it)
// 	{
// 		end = std::upper_bound( sorted.begin(), sorted.end(), *it );
// 		sorted.insert( end, *it );
// 	}
// 	return sorted;
// }

// void	PmergeMe::listSort()
// {
	// findMaxMakePairlist();
	// mergeSort();
	// return listInsertSort();
// }