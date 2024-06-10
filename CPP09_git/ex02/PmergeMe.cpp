/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:07 by yachen            #+#    #+#             */
/*   Updated: 2024/06/10 11:58:51 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <string>
#include <cstdlib>
#include <algorithm>
using std::cout;

PmergeMe::PmergeMe( char** sequence ) : _unpaired( -1 ), _sequence( sequence ) {}

PmergeMe::PmergeMe( const PmergeMe& other )
{
	_sequence = other._sequence;
	_unpaired = -1;
}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=( const PmergeMe& other )
{
	if (this != &other)
	{
		_sequence = other._sequence;
		_unpaired  = -1;
	}
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
	}
}

//************************************************************************************************
//							algorithm Ford Johson using vector
//
//************************************************************************************************

std::vector<std::pair<int, int> >	PmergeMe::makeVectorPairlist( const std::vector<int>& unsorted )
{
	std::vector<std::pair<int, int> >	pairNb;
	std::vector<int>::const_iterator	it = unsorted.begin();
	std::vector<int>::const_iterator	end = unsorted.end();
	if ( unsorted.size() % 2 != 0 )
	{
		end = unsorted.end() - 1;
		_unpaired = *end;
	}
	for (; it != end; it+=2)
	{
		std::pair<int, int> pair = std::make_pair( *it, *(it + 1) );
		if (pair.first < pair.second)
			std::swap( pair.first, pair.second );
		pairNb.push_back( pair );
	}
	return pairNb;
}

void	PmergeMe::mergeVector( std::vector<std::pair<int, int> >& pair, const int left, const int mid, const int right )
{
	int	leftSize = mid - left + 1;
	int	rightSize = right - mid;
	std::vector<std::pair<int, int> >	leftArr;
	std::vector<std::pair<int, int> >	rightArr;
	for (int i = 0; i < leftSize; i++)			// copy pair left content to left vector and right content to right vector.
		leftArr.push_back(pair[left + i]);
	for (int i = 0; i < rightSize; i++)
		rightArr.push_back(pair[mid + 1 + i]);
	int	i = 0, j = 0, k = left;
	while (i < leftSize && j < rightSize)		// compare left and right vector nb to range pair nb.
	{
		if (leftArr[i].first <= rightArr[j].first)
			pair[k++] = leftArr[i++];
		else
			pair[k++] = rightArr[j++];
	}
	while (i < leftSize)						// adjust the remaining values.
    		pair[k++] = leftArr[i++];
    while (j < rightSize)
			pair[k++] = rightArr[j++];
}

// make pair list sorted with :pair->first = max, in ascending order.
void	PmergeMe::vectorMergeSort( std::vector<std::pair<int, int> >& pair, const int begin, const int end )
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	vectorMergeSort(pair, begin, mid );
	vectorMergeSort(pair, mid + 1, end );
	mergeVector(pair, begin, mid, end );
}

void	PmergeMe::vectorInsertSort( std::vector<int>& sorted, const std::vector<std::pair<int, int> >& pair )
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
	parseSequence();
	std::vector<int>	unsorted = sequenceToNblist<std::vector<int> >();
	if (unsorted.size() == 1)
		return unsorted;
	else if (unsorted.size() == 2)
	{
		if (unsorted[0] > unsorted[1])
			std::swap( unsorted[0], unsorted[1] );
		return unsorted;
	}
	std::vector<int>	sortedList;
	std::vector<std::pair<int, int> >	pair = makeVectorPairlist( unsorted );
	vectorMergeSort(pair, 0, pair.size() - 1 );
	vectorInsertSort( sortedList, pair);
	return sortedList;
}

//************************************************************************************************
//							algorithm Ford Johson using list
//
//************************************************************************************************

std::list<std::pair<int, int> >	PmergeMe::makeListPairlist( const std::list<int>& unsorted )
{
	std::list<std::pair<int, int> >	pairNb;
	std::list<int>::const_iterator	it = unsorted.begin();
	std::list<int>::const_iterator	end = unsorted.end();
	if ( unsorted.size() % 2 != 0 )
	{
		--end;
		_unpaired = *end;
	}
	while (it != end)
	{
		int	first = *it++;
		int	second = *it++;
		std::pair<int, int> pair = std::make_pair( first, second );
		if (pair.first < pair.second)
			std::swap( pair.first, pair.second );
		pairNb.push_back( pair );
	}
	return pairNb;
}

void	PmergeMe::mergeList( std::list<std::pair<int, int> >& pair, const int left, const int mid, const int right )
{
	std::list<std::pair<int, int> >	leftArr;
	std::list<std::pair<int, int> >	rightArr;
	std::list<std::pair<int, int> >::iterator	it = pair.begin();
	std::advance( it, left );			// move it to start position.
	for (int i = left; i <= mid ; i++)
		leftArr.push_back(*it++);				// do half left copy to leftArr and the rest half copy to rightArr.
	for (int i = mid + 1; i <= right; i++)
		rightArr.push_back(*it++);
	std::list<std::pair<int, int> >::iterator	left_it = leftArr.begin();
    std::list<std::pair<int, int> >::iterator	right_it = rightArr.begin();
    it = pair.begin();
    std::advance(it, left);
	while (left_it != leftArr.end() && right_it != rightArr.end())
	{
		if (left_it->first <= right_it->first)
			*it++ = *left_it++;
		else									// range pair value in ascending order.
			*it++ = *right_it++;
	}
    while (left_it != leftArr.end())
		*it++ = *left_it++;
    while (right_it != rightArr.end())			// adjust the remaining values.
        *it++ = *right_it++;
}

// make pair list sorted with :pair->first = max, in ascending order.
void	PmergeMe::listMergeSort( std::list<std::pair<int, int> >& pair, const int begin, const int end )
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	listMergeSort(pair, begin, mid );
	listMergeSort(pair, mid + 1, end );
	mergeList(pair, begin, mid, end );
}

void	PmergeMe::listInsertSort( std::list<int>& sorted, const std::list<std::pair<int, int> >& pair )
{
	std::list<std::pair<int, int> >::const_iterator	pair_it = pair.begin();
	std::list<int>	unsorted;
	if (_unpaired != -1)
		unsorted.push_back( _unpaired );
	sorted.push_back( (pair_it++)->second );
	for (; pair_it != pair.end(); ++pair_it)
		unsorted.push_back( pair_it->second );
	for (pair_it = pair.begin(); pair_it != pair.end(); ++pair_it)
		sorted.push_back( pair_it->first );
	std::list<int>::iterator	end;
	std::list<int>::iterator	unsorted_it = unsorted.begin();
	for (size_t i = 0; i < unsorted.size(); i++)
	{
		end = std::upper_bound( sorted.begin(), sorted.end(), *unsorted_it );
		sorted.insert( end, *unsorted_it );
		unsorted_it++;
	}
}

std::list<int>	PmergeMe::listMergeInsertSort()
{
	parseSequence();
	std::list<int>	unsorted = sequenceToNblist<std::list<int> >();
	if (unsorted.size() == 1)
		return unsorted;
	else if (unsorted.size() == 2)
	{
		unsorted.sort();
		return unsorted;
	}
	std::list<int>	sortedList;
	std::list<std::pair<int, int> >	pair = makeListPairlist( unsorted );
	listMergeSort(pair, 0, pair.size() - 1 );
	listInsertSort( sortedList, pair);
	return sortedList;
}

