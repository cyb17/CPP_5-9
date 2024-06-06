/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:07 by yachen            #+#    #+#             */
/*   Updated: 2024/06/06 18:07:38 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <string>
#include <cstdlib>
using std::cout;

PmergeMe::PmergeMe( char** sequence ) : _sequence( sequence )
{
	parseSequence();
	// pushTolist();
	// pushToVector();
}

PmergeMe::PmergeMe( const PmergeMe& other ) : _sequence( other._sequence ) {}

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
        _vBefore.push_back( static_cast<int>( number ) );
	}
}

// void	PmergeMe::pushToVector()
// {
// 	long	nb;
// 	int		i = -1;
// 	while (_sequence[++i])
// 	{
// 		nb = atol( _sequence[i] );
// 		if (nb > std::numeric_limits<int>::max())
// 		{
// 			std::string s( _sequence[i] );
// 			throw std::invalid_argument( "too large number for a int: " + s );
// 		}
// 		else
// 			_vBefore.push_back( static_cast<int>(nb) );
// 	}
// }	

void	PmergeMe::findMaxMakePairlist()
{
	std::vector<int>::iterator	it = _vBefore.begin();
	std::vector<int>::iterator	end = _vBefore.end();
	if ( _vBefore.size() % 2 != 0 )
	{
		end = _vBefore.end() - 1;
		_unpaired = *end;
	}
	for (; it != end; it+=2)
	{
		std::pair<int, int> pair = std::make_pair( *it, *(it + 1) );
		if (pair.first < pair.second)
			std::swap( pair.first, pair.second );
		_pair.push_back( pair );
	}

	cout << "========================================pair find max \n";
	std::vector<std::pair<int, int> >::iterator	i = _pair.begin();
	for (; i != _pair.end(); i++)
		cout << "pair :" << i->first << '\t' << i->second << std::endl;
	cout << "unpaired: " << _unpaired << std::endl;
	cout << "_pair size: " << _pair.size() << std::endl;
}

// void	PmergeMe::merge( const int begin, const int mid, const int end )
// {
// 	int	leftSize = mid - begin + 1;
// 	int	rightSize = end - mid;

// 	std::vector<std::pair<int, int> >	leftArr;
// 	std::vector<std::pair<int, int> >	rightArr;
// 	std::copy( _pair.begin() + begin, _pair.begin() + mid + 1, std::back_inserter( leftArr ));
// 	std::copy( _pair.begin() + mid + 1, _pair.begin() + end + 1, std::back_inserter( rightArr ));
	
// 	int	i = 0, j = 0, k = begin;
// 	while (i < leftSize && j < rightSize)
// 	{
// 		std::cout << "mid = " << mid << '\t' << "left[i] = " << leftArr[i].first << '\t' << "right[i] = " << rightArr[j].first << '\n';
// 		if (leftArr[i].first <= rightArr[j].first)
// 			_pair[k++] = leftArr[i++];
//         else
//             _pair[k++] = rightArr[j++];
// 	}
// 	while (i < leftSize)
//     		_pair[k++] = leftArr[i++];
//     while (j < rightSize)
// 			_pair[k++] = rightArr[j++];
// }

void	printArrPair( std::vector<std::pair<int, int> > arr )
{	
	for (std::vector<std::pair<int, int> >::iterator it = arr.begin(); it != arr.end(); ++it)
	{
		cout << "first: "<< it->first << "\tsecond: " << it->second << '\n';
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

	cout << "-------------------------------leftArr \n";
	printArrPair( leftArr );
	cout << "-------------------------------rightArr \n";
	printArrPair( rightArr );

	int	i = 0, j = 0, k = left;
	while (i < leftSize && j < rightSize)
	{
		if (mid == 4)
		cout << "leftArr[i].first: " << leftArr[i].first << "\trightArr[i].first: " << rightArr[j].first << '\n';
		if (leftArr[i].first <= rightArr[j].first)
		{
			_pair[k++] = leftArr[i++];
		}
		else
		{
			_pair[k++] = rightArr[j++];
		}
		cout << "i = " << i << "\tj = " << j << '\n';
	}
	
	while (i < leftSize)
    		_pair[k++] = leftArr[i++];
    while (j < rightSize)
			_pair[k++] = rightArr[j++];
	
	cout << "-------------------------------_pair merged \n";
	cout << "left = " << left << "\tmid = " << mid << "\tright = " << right << '\n'; 
	cout << "merge\tleftSize = " << leftSize << "\trightSize = " << rightSize << '\n'; 
	printArrPair( _pair );
	
	cout << "========================================merge \n";

}

void	PmergeMe::mergeSort( const int begin, const int end )
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	cout << "recursive left value\n";
	mergeSort( begin, mid );
	cout << "recursive right value\n";
	mergeSort( mid + 1, end );
	merge( begin, mid, end );
}

void	PmergeMe::printMergeInfo()
{
	std::vector<std::pair<int, int> >::iterator	it = _pair.begin() + 2;
	std::cout << _pair.size() << '\n';
	for (; it != _pair.end() + 2; it++)
	{
		std::cout << "\tprint :" << it->first << '\t' << it->second << std::endl;
	}	
	// cout << "Before : ";
	// std::vector<int>::iterator	it = _vBefore.begin();
	// for (; it < _vBefore.end(); it++)
	// 	cout << *it << '\t';
	// cout << '\n';
}