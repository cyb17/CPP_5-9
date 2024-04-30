/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:28:22 by yachen            #+#    #+#             */
/*   Updated: 2024/04/30 17:28:50 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

using std::cout
using std::endl

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
	cout << BLUE << "ScalarConverter : operator assignement called" << RESET << endl;
	return *this;
}

bool	ScalarConverter::IsEmpty( const std::string& str ) const
{
	if (str.empty())
		return true;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return false;
	}
	return true;
}

bool	ScalarConverter::IsCharLiteral( const std::string& str ) const
{
	if (str.length() > 1)
		return false;
	return true;
}

std::string	ScalarConverter::StrWithoutWhitespace( std::string str )
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

bool	ScalarConverter::IsIntLiteral( const std::string& str ) const
{
	int i = 0;
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

bool	ScalarConverter::IsFloatLiteral( const std::string str ) const
{
	int i = 0;
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

bool	ScalarConverter::IsDoubleLiteral( const std::string str ) const
{
	int i = 0;
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

static void	ScalarConverter::Convert( std::string str )
{
	
}