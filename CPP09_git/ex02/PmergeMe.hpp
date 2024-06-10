/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:08:24 by yachen            #+#    #+#             */
/*   Updated: 2024/06/10 11:54:46 by yachen           ###   ########.fr       */
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
#include <cstdlib>

class	PmergeMe
{
	private:

		int									_unpaired;
		char**								_sequence;
		
		void				parseSequence();
		template<typename T>
		T					sequenceToNblist();
		
		std::vector<std::pair<int,int> >	makeVectorPairlist( const std::vector<int>& unsorted );
		void								mergeVector( std::vector<std::pair<int, int> >& pair, const int begin, const int mid, const int end );
		void								vectorMergeSort( std::vector<std::pair<int, int> >& pair, const int begin, const int end );
		void								vectorInsertSort( std::vector<int>& sorted, const std::vector<std::pair<int, int> >& pair );
		
		std::list<std::pair<int,int> >		makeListPairlist( const std::list<int>& unsorted );
		void								listMergeSort( std::list<std::pair<int, int> >& pair, const int begin, const int end );
		void								mergeList( std::list<std::pair<int, int> >& pair, const int left, const int mid, const int right );
		void								listInsertSort( std::list<int>& sorted, const std::list<std::pair<int, int> >& pair );

	public:
	
		PmergeMe( char** sequence );
		PmergeMe( const PmergeMe& other );
		~PmergeMe();

		PmergeMe&	operator=( const PmergeMe& other );
		
		template<typename T>
		void				printProgramInfo( T& c );
		
		std::vector<int>	vectorMergeInsertSort();
		std::list<int>		listMergeInsertSort();
		
};

template<typename T>
void	PmergeMe::printProgramInfo( T& c )
{
	if (_sequence)
	{
		std::cout << "\nBefore: " << BLUE;
		int i = - 1;
		while (_sequence[++i] && i < 10)
			std::cout << _sequence[i] << '\t';
		if (_sequence[i])
			std::cout << "[...]\n";
		std::cout << DEF << "\nAfter: " << YELLOW;
		typename T::const_iterator	it = c.begin();
		for (; it != c.end() && i > 0; ++it, --i)
			std::cout << *it << '\t';
		if (c.size() > 10 )
			std::cout << "[...]\n";
		std::cout << "\n\n" << DEF;
	}
}

template<typename T>
T	PmergeMe::sequenceToNblist()
{
	T	unsortedNb;
	int	k = -1;
	while (_sequence[++k])
		unsortedNb.push_back( std::atoi( _sequence[k] ) );
	return unsortedNb;
}

// template <typename T>
// void	printContainer( const T& c )
// {
// 	typename T::const_iterator	it = c.begin();
// 	std::cout << "container content : \n";
// 	for (; it != c.end(); ++it)
// 		std::cout << *it << '\t';
// 	std::cout << std::endl;
// }

// template<typename T>
// void	printPair(const T& c) 
// {   
// 	std::cout << "pair : \n";
//     typename T::const_iterator it = c.begin(); // Utilisation de const_iterator pour les conteneurs const
//     for (; it != c.end(); ++it)
// 	{
//     	std::cout << "first : " << it->first << '\t';
// 	}
// 	std::cout << std::endl;
// 	it = c.begin();
//     for (; it != c.end(); ++it)
//     {
// 		std::cout << "second: " << it->second << '\t';
// 	}
// 	std::cout << std::endl;
// }   

#endif