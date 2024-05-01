/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:28:22 by yachen            #+#    #+#             */
/*   Updated: 2024/05/01 11:30:46 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>

using std::cout;
using std::endl;

ScalarConverter::ScalarConverter()
{
	cout << B_BLUE << "ScalarConverter : Default constructor called" << RESET << endl;
}

ScalarConverter::~ScalarConverter()
{
	cout << B_MAGENTA << "ScalarConverter : Default destructor called" << RESET << endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& other)
{
	*this = other;
	cout << BLUE << "ScalarConverter : copy constructor called" << RESET << endl;
}

ScalarConverter&	ScalarConverter::operator = ( const ScalarConverter& other )
{
	if ( this != &other )
		*this = other;
	cout << BLUE << "ScalarConverter : operator assignement called" << RESET << endl;
	return *this;
}

bool	IsEmpty( const std::string& str )
{
	if (str.empty())
		return true;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return false;
	}
	return true;
}

bool	IsCharLiteral( const std::string& str )
{
	if (str.length() > 1 || isdigit(str[0]))
		return false;
	return true;
}

std::string	StrWithoutWhitespace( std::string str )
{
	int	len = str.length();
	int	start = 0;
	while (start < len && (str[start] == ' ' || str[start] == '\t'))
		start++;
	int end = len - 1;
	while (end >= start && (str[end] == ' ' || str[end] == '\t'))
		end--;
	return str.substr(start, end - start + 1);
}

bool	IsIntLiteral( const std::string& str )
{
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	const char* cstr = str.c_str();
	if (atol(cstr) > INT_MAX || atol(cstr) < INT_MIN)
		return false;
	return true;
}

bool	IsFloatLiteral( const std::string str )
{
	size_t i = 0;
	int	f = 0;
	int	point = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if ((str.compare("+inff") == 0) || (str.compare("-inff") == 0)
		|| (str.compare("nanf") == 0))
		return true;
	for (; i < str.length(); i++)
	{
		if (str[i] == '.')
			point++;
		else if (str[i] == 'f')
			f++;
		else if (str[i] < '0' || str[i] > '9')
			return false;
	}	
	if (point != 1 || f != 1 || (str[str.length() - 1] != 'f')
		|| (str[0] == '.' || str[str.length() - 2] == '.'))
			return false;
	return true;
}

bool	IsDoubleLiteral( const std::string str )
{
	size_t i = 0;
	int	point = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if ((str.compare("+inf") == 0) || (str.compare("-inf") == 0)
		|| (str.compare("nan") == 0))
		return true;
	for (; i < str.length(); i++)
	{
		if (str[i] == '.')
			point++;
		else if (str[i] < '0' || str[i] > '9')
			return false;
	}
	if (point != 1 || (str[0] == '.' || str[str.length() - 1] == '.'))
			return false;
	return true;
}

#define CHAR 5
#define INT	6
#define	FLOAT 7
#define	DOUBLE 8
#define STRING 9

void	ScalarConverter::Convert( std::string str )
{
	int	type = STRING;
	
	if (IsCharLiteral(str))
		type = CHAR;
	else if (IsIntLiteral(str))
		type = INT;
	else if (IsFloatLiteral(str))
		type = FLOAT;
	else if (IsDoubleLiteral(str))
		type = DOUBLE;
	
}