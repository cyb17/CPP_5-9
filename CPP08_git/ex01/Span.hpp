/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:07 by yachen            #+#    #+#             */
/*   Updated: 2024/05/16 17:56:54 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <deque>
#include <algorithm>
#include <iostream>
#define RESET "\e[0m"
#define BLUE "\e[34m"
#define RED "\e[31m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"

class	Span
{
	private:

		unsigned int	sizeMax;
		std::deque<int> monSpan;
		int				shortest;
		int				longest;

	public:

		Span( unsigned int n );
		Span( const Span& other );
		Span&	operator=( const Span& other );
		~Span();

		void			addNumber( int const nb );
		std::deque<int>	getMonSpan() const;
		int				shortestSpan();
		int				longestSpan();
		void			addLotNumber( unsigned int n );

};

void	printContainerValue( std::deque<int> container );

#endif