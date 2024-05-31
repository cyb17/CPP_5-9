/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:10:38 by yachen            #+#    #+#             */
/*   Updated: 2024/05/31 14:17:28 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"
#include <stdexcept>
#include <cctype>

RPN::RPN() {}

RPN::RPN( const RPN& other ) {}

RPN::~RPN() {}

RPN&	RPN::operator=( const RPN& other ) {}

int	RPN::calculateResult( const char* exp )
{
	std::stack<int>	stack;
	
	while (exp[i])
	{
		if (isspace( exp[i] ))
			continue;
		else if ( isdigit( exp[i]) )
			stack.push( exp[i] - '0' )
		else if ( isOperator( exp[i] ) && stack.size() > 1)
		{
			int	operand1 = stack.top();
			stack.pop();
			int operand2 = stack.top();
			stack.pop();
			int	rslt = doOperation( exp[i], operand2, operand1 );
			stack.push( rslt );
		}

	}
}

bool	RNP::isOperator( char c )
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

int	RPN::doOperation( char optor, int op2, int op1 )
{
	switch(optor)
	{
		case '+':
			return op2 + op1;
		case '-':
			return op2 - op1;
		case '*':
			return op2 * op1;
		case '/':
			return op2 / op1;
		default:
			breack
	}
}