/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:08:24 by yachen            #+#    #+#             */
/*   Updated: 2024/06/07 17:50:52 by yachen           ###   ########.fr       */
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
		std::vector<std::pair<int, int> >	_pair;
		
		void				parseSequence();
		void				merge( const int begin, const int mid, const int end );
		void				MakePairlist();
		void				mergeSort( const int begin, const int end );
		std::vector<int>	vectorInsertSort();
		std::list<int>		listInsertSort();

	public:
	
		PmergeMe( char** sequence );
		PmergeMe( const PmergeMe& other );
		~PmergeMe();

		PmergeMe&	operator=( const PmergeMe& other );
		
		std::vector<int>	vectorSort();
		std::list<int>		listSort();
		void				printMergeInfo();
};

template <typename T>
void	printContainer( T& c )
{
	typename T::iterator	it = c.begin();
	for (; it != c.end(); ++it)
		std::cout << "c : " << *it << '\t';
	std::cout << std::endl;
}

#endif