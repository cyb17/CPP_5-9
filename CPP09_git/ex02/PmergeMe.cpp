/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:07 by yachen            #+#    #+#             */
/*   Updated: 2024/06/06 13:44:23 by yachen           ###   ########.fr       */
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

	// std::vector<std::pair<int, int> >::iterator	i = _pair.begin();
	// for (; i != _pair.end(); i++)
	// 	cout << "pair :" << i->first << '\t' << i->second << std::endl;
	// cout << _unpaired << std::endl;
}

void	PmergeMe::merge( const int begin, const int mid, const int end )
{
	int	leftSize = end - mid + 1;
	int	rightSize = end - mid;

	std::vector<std::pair<int, int> >	leftArr;
	std::vector<std::pair<int, int> >	rightArr;
	std::vector<std::pair<int, int> >	_mergeArr;
	std::copy( _pair.begin() + begin, _pair.begin() + mid, std::back_inserter( leftArr ));
	std::copy( _pair.begin() + mid + 1, _pair.begin() + end, std::back_inserter( rightArr ));
	int	i = 0;
	int	j = 0;
	while (i < leftSize && j < rightSize)
	{
		if (leftArr[i].first <= rightArr[j].first)
			_mergeArr.push_back( leftArr[i++] );
		else		
			_mergeArr.push_back( rightArr[j++] );
	}
	while (i < leftSize)
        _mergeArr.push_back( leftArr[i++] );
    while (j < rightSize)
        _mergeArr.push_back( rightArr[j++] );
}

void	PmergeMe::mergeSort( const int begin, const int end )
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSort( begin, mid );
	mergeSort( mid + 1, end );
	merge( begin, mid, end );
}

void	PmergeMe::printMergeInfo()
{
	std::vector<std::pair<int, int> >::iterator	it = _mergeArr.begin();
	for (; it != _mergeArr.end(); it++)
		std::cout << "\tmerge :" << it->first << '\t' << it->second << std::endl;
	// cout << "Before : ";
	// std::vector<int>::iterator	it = _vBefore.begin();
	// for (; it < _vBefore.end(); it++)
	// 	cout << *it << '\t';
	// cout << '\n';
}