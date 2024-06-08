/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:07 by yachen            #+#    #+#             */
/*   Updated: 2024/06/08 14:56:30 by yachen           ###   ########.fr       */
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
        // _unsortedList.push_back( static_cast<int>( number ) );
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
									// split to 2 vector : left nb and right nb.
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
									// add the rest to pair.
	while (i < leftSize)
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

// std::list<std::pair<int, int> >	PmergeMe::makelistPairlist( const std::list<int>& unsorted )
// {
// 	std::list<std::pair<int, int> >	pairNb;
// 	std::list<int>::const_iterator	it = unsorted.begin();
// 	std::list<int>::const_iterator	end = unsorted.end();
// 	if ( unsorted.size() % 2 != 0 )
// 	{
// 		end = unsorted.end() - 1;
// 		_unpaired = *end;
// 	}
// 	for (; it != end; it+=2)
// 	{
// 		std::pair<int, int> pair = std::make_pair( *it, *(it + 1) );
// 		if (pair.first < pair.second)
// 			std::swap( pair.first, pair.second );
// 		pairNb.push_back( pair );
// 	}
// 	return pairNb;
// }

// void	PmergeMe::mergeList( std::vector<std::pair<int, int> >& pair, const int left, const int mid, const int right )
// {
// 									// split pair to 2 list : left nb and right nb.
// 	int	leftSize = mid - left + 1;
// 	int	rightSize = right - mid;
// 	std::list<std::pair<int, int> >	leftArr;
// 	std::list<std::pair<int, int> >	rightArr;
// 	for (int i = 0; i < leftSize; i++)
// 		leftArr.push_back(pair[left + i]);
// 	for (int i = 0; i < rightSize; i++)
// 		rightArr.push_back(pair[mid + 1 + i]);
// 									// compare the max of each pair to make pair sorted.
// 	int	i = 0, j = 0, k = left;
// 	while (i < leftSize && j < rightSize)
// 	{
// 		if (leftArr[i].first <= rightArr[j].first)
// 			pair[k++] = leftArr[i++];
// 		else
// 			pair[k++] = rightArr[j++];
// 	}
// 									// add the rest to pair.
// 	while (i < leftSize)
//     		pair[k++] = leftArr[i++];
//     while (j < rightSize)
// 			pair[k++] = rightArr[j++];
// }

// // make pair list sorted with :pair->first = max, in ascending order.
// void	PmergeMe::listMergeSort( std::list<std::pair<int, int> >& pair, const int begin, const int end )
// {
// 	if (begin >= end)
// 		return;
// 	int mid = begin + (end - begin) / 2;
// 	listMergeSort(pair, begin, mid );
// 	listMergeSort(pair, mid + 1, end );
// 	mergeList(pair, begin, mid, end );
// }

// void	PmergeMe::listInsertSort( std::list<int>& sorted, const std::list<std::pair<int, int> >& pair )
// {
// 	std::list<int>	unsorted;
// 	if (_unpaired != -1)
// 		unsorted.push_back( _unpaired );
// 	sorted.push_back( pair[0].second );
// 	for (size_t i = 0; i < pair.size(); i++)
// 		sorted.push_back( pair[i].first );
// 	for (size_t i = 1; i < pair.size(); i++)
// 		unsorted.push_back( pair[i].second );
// 	std::list<int>::iterator	end;
// 	for (size_t i = 0; i < unsorted.size(); i++)
// 	{
// 		end = std::upper_bound( sorted.begin(), sorted.end(), unsorted[i] );
// 		sorted.insert( end, unsorted[i] );
// 	}
// }

// std::list<int>	PmergeMe::listMergeInsertSort()
// {
// 	parseSequence();
// 	std::list<int>	unsorted = sequenceToNblist<std::list<int> >();
// 	if (unsorted.size() == 1)
// 		return unsorted;
// 	else if (unsorted.size() == 2)
// 	{
// 		if (unsorted[0] > unsorted[1])
// 			std::swap( unsorted[0], unsorted[1] );
// 		return unsorted;
// 	}
// 	std::list<int>	sortedList;
// 	std::list<std::pair<int, int> >	pair = makeVectorPairlist( unsorted );
// 	listMergeSort(pair, 0, pair.size() - 1 );
// 	ListInsertSort( sortedList, pair);
// 	return sortedList;
// }

