/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:14:35 by yachen            #+#    #+#             */
/*   Updated: 2024/05/31 13:32:11 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#define DEF "\e[0m"
#define BLUE "\e[34m"
#define RED "\e[31m"
#define YELLOW "\e[33m"
#define GREEN "\e[32m"
#include <stack>

class	RPN
{
	private:
		
		// int			_result;
		std::stack	_stack;
		
		bool	isValidExpression();
		
	public:
	
		RPN();
		RPN( const RPN& other );
		~RPN();

		RPN&	operator=( const RPN& other );
		
		int	calculateResult( const char* exp );
		
};


#endif