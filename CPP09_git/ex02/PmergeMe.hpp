/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:08:24 by yachen            #+#    #+#             */
/*   Updated: 2024/06/08 11:54:31 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP
#define DEF "\e[0m"
#define BLUE "\e[34m"
#define RED "\e[31m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>
#include <utility>

class	PmergeMe
{
	private:

		int									_unpaired;
		char**								_sequence;
		std::vector<int>					_unsortedList;
		
		void			parseSequence();
		template<typename T>
		T				makePairlist();
		void			merge( std::vector<std::pair<int, int> >& pair, const int begin, const int mid, const int end );
		void			mergeSort( std::vector<std::pair<int, int> >& pair, const int begin, const int end );
		void			vectorInsertSort( std::vector<int>& sorted, std::vector<std::pair<int, int> >& pair );
		std::list<int>	listInsertSort();

	public:
	
		PmergeMe( char** sequence );
		PmergeMe( const PmergeMe& other );
		~PmergeMe();

		PmergeMe&	operator=( const PmergeMe& other );
		
		std::vector<int>	vectorMergeInsertSort();
		void				printProgramInfo( const std::vector<int>& v );
		
};

// Make list of pair nb : first = max | second = min, _unpaired = unpaired nb if exist. 
template<typename T> 
T	PmergeMe::makePairlist()
{
	T	pairNb;
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
		pairNb.push_back( pair );
	}
	return pairNb;
}

template <typename T>
void	printContainer( const T& c )
{
	typename T::const_iterator	it = c.begin();
	std::cout << "container content : \n";
	for (; it != c.end(); ++it)
		std::cout << *it << '\t';
	std::cout << std::endl;
}

template<typename T>
void	printPair(const T& c) 
{   
	std::cout << "pair : \n";
    typename T::const_iterator it = c.begin(); // Utilisation de const_iterator pour les conteneurs const
    for (; it != c.end(); ++it)
	{
    	std::cout << "first : " << it->first << '\t';
	}
	std::cout << std::endl;
	it = c.begin();
    for (; it != c.end(); ++it)
    {
		std::cout << "second: " << it->second << '\t';
	}
	std::cout << std::endl;
}   

#endif