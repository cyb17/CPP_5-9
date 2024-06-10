/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:10:38 by yachen            #+#    #+#             */
/*   Updated: 2024/06/10 14:31:24 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>
#include <cctype>
#include <cstring>
#include <climits>
#include <iostream>

RPN::RPN() {}

RPN::RPN( const RPN& other ) : _c( other._c ) {}

RPN::~RPN() {}

RPN&	RPN::operator=( const RPN& other )
{
	if (this != &other)
		_c = other._c;
	return *this;
}

int	RPN::calculateResult( const char* exp )
{
	long	rslt = 0;
	size_t	i = -1;
	std::stack<int>	stack;
	
	while (exp[++i])
	{
		if ( isdigit( exp[i]) && i == strlen(exp) - 1)
			throw std::invalid_argument( "expression must terminated with a operator: +,-,*,/" );
		if (isspace( exp[i] ))
			continue;
		else if ( isdigit( exp[i]))
			stack.push( exp[i] - '0' );
		else if ( isOperator( exp[i] ) && stack.size() > 1)
		{
			long	operand1 = stack.top();
			stack.pop();
			long	operand2 = stack.top();
			stack.pop();
			if ( operand1 == 0 && operand2 == 1 && exp[i] == '/')
				throw std::invalid_argument( "1 / 0 is not possible" );
			rslt = doOperation( exp[i], operand2, operand1 );
			if (rslt < INT_MIN || rslt > INT_MAX)
				throw std::runtime_error( "result exceeded the limit of an int" );
			stack.push( rslt );
		}
		else
			throw std::invalid_argument( "invalid expression" );
	}
	if (stack.empty())
		throw std::invalid_argument( "expression can not be NULL or empty" );
	return static_cast<int>(rslt);
}

//***********************************************************************************
//				Private functions definitions
//
//***********************************************************************************

bool	RPN::isOperator( char c )
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

long	RPN::doOperation( char optor, long op2, long op1)
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
	}
	return -1;
}