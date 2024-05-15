/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:21:07 by yachen            #+#    #+#             */
/*   Updated: 2024/05/15 15:33:25 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H

#include <vector>
#include <algorithm>

class	Span
{
	private:

		std::vector monSpan;

	public:

		Span( unsigned int n );
		Span( const Span& other );
		Span&	operator=( const Span& other );
		~Span();

		void	addNumber( int const nb );
};

#endif