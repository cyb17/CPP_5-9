/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:08:24 by yachen            #+#    #+#             */
/*   Updated: 2024/06/04 17:43:27 by yachen           ###   ########.fr       */
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

class	PmergeMe
{
	private:

		char**				_sequence;
		std::vector<int>	_vBefore;
		std::list<int>		_lBefore;
		
		void	parseSequence();

	public:
	
		PmergeMe( char** sequence );
		PmergeMe( const PmergeMe& other );
		~PmergeMe();

		PmergeMe&	operator=( const PmergeMe& other );
		
		void	pushToVector();
		// void	pushTolist();
		// std::vector<int>	vectorMerge();
		// std::list<int>		listMerge();
		void				printMergeInfo();
};

#endif