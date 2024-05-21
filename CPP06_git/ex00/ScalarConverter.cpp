/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:28:22 by yachen            #+#    #+#             */
/*   Updated: 2024/05/21 17:12:03 by yachen           ###   ########.fr       */
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

bool	isEmpty( const std::string& str )
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

bool	isCharLiteral( const std::string& str )
{
	if (str.length() > 1 || isdigit(str[0]))
		return false;
	return true;
}

std::string	strWithoutWhitespace( std::string str )
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

bool	isIntLiteral( const std::string& str )
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
	{
		cout << RED << "The provide string is a number, but it exceeded the limit of an int." << RESET << endl;
		return false;
	}
	return true;
}

bool	isFloatLiteral( const std::string str )
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

bool	isDoubleLiteral( const std::string str )
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

void	ScalarConverter::convert( std::string str )
{
	cout.setf(std::ios::fixed);
	cout.precision(1);
	if (isCharLiteral(str))
	{
		cout << CYAN << "char: '" << static_cast<char>(str[0]) << "'" << endl;
		cout << "int: " << static_cast<int>(str[0]) << endl;
		cout << "float: " << static_cast<float>(str[0]) << "f" << endl;
		cout << "double: " << static_cast<double>(str[0]) << RESET << endl;
	}
	else if (isIntLiteral(str))
	{
		int	i = atoi(str.c_str());
		if (i > 32 && i < 127)
			cout << CYAN << "char: '" << static_cast<char>(i) << "'" << endl;
		else
			cout << CYAN << "char: no displayable" << endl;
		cout << "int: " << i << endl;
		cout << "float: " << static_cast<float>(i) << "f" << endl;
		cout << "double: " << static_cast<double>(i) << RESET << endl;
	}
	else if (isFloatLiteral(str))
	{
		float	f = strtof(str.c_str(), NULL);
		
		if ((str.compare("+inff") == 0) || (str.compare("-inff") == 0)
		|| (str.compare("nanf") == 0))
			cout << CYAN << "char: impossible\n" << "int: impossible" << endl;
		else
		{
			int	nb = static_cast<int>(f);
			if (nb > 32 && nb < 127)
				cout << CYAN << "char: '" << static_cast<char>(nb) << "'" << endl;
			else
				cout << CYAN << "char: impossible\n";
			cout << "int: " << static_cast<int>(f) << endl;
		}
		cout << "float: " << f << "f" << endl;
		cout << "double: " << static_cast<float>(f) << RESET << endl;
	}
	else if (isDoubleLiteral(str))
	{
		double	d = atof(str.c_str());
		
		if ((str.compare("+inf") == 0) || (str.compare("-inf") == 0)
		|| (str.compare("nan") == 0))
			cout << CYAN << "char: impossible\n" << "int: impossible" << endl;
		else
		{
			int	nb = static_cast<int>(d);
			if (nb > 32 && nb < 127)
				cout << CYAN << "char: '" << static_cast<char>(nb) << "'" << endl;
			else
				cout << CYAN << "char: impossible\n";
			cout << "int: " << static_cast<int>(d) << endl;
		}
		cout << "float: " << static_cast<float>(d) << "f" << endl;
		cout << "double: " << d << RESET << endl;
	}
	else
		cout << RED <<  "The provided string cannot be converted\n" << RESET;
}