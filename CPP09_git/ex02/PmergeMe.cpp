/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:02:07 by yachen            #+#    #+#             */
/*   Updated: 2024/06/04 17:50:56 by yachen           ###   ########.fr       */
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
	pushToVector();
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
		size_t	i = 0;
		for (; i < nbStr.size() - 1; i++)
		{
			if (!std::isspace( nbStr[i] ))
				break;
		}
		if (i == nbStr.size() - 1)
			throw std::invalid_argument( "nb can not be a empty string" );
		else
		{
			while (!std::isspace( nbStr[i]) && i < nbStr.size() - 1)
				i++;
			if (i != nbStr.size() -1 && nbStr.find_first_not_of( " 	", i ) != std::string::npos)
				throw std::invalid_argument( "not a nb: " + nbStr );
		}
		if (nbStr.find_first_not_of( "0123456789 	", 0 ) != std::string::npos)
			throw std::invalid_argument( "nb can only be a positive integer" );
	}
}

void	PmergeMe::pushToVector()
{
	long	nb;
	int		i = -1;
	while (_sequence[++i])
	{
		nb = atol( _sequence[i] );
		if (nb > std::numeric_limits<int>::max())
		{
			std::string s( _sequence[i] );
			throw std::invalid_argument( "too large number for a int: " + s );
		}
		else
			_vBefore.push_back( static_cast<int>(nb) );
	}
}	

void	PmergeMe::printMergeInfo()
{
	cout << "Before : ";
	std::vector<int>::iterator	it = _vBefore.begin();
	for (; it < _vBefore.end(); it++)
		cout << *it << '\t';
	cout << '\n';
}