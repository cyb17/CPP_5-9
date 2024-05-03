/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:01:24 by yachen            #+#    #+#             */
/*   Updated: 2024/05/03 14:49:07 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include "color.h"

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter( const ScalarConverter& other );
		ScalarConverter&	operator= ( const ScalarConverter& other );
				
	public:
	
		~ScalarConverter();
		static void convert( std::string str );
};

bool	isEmpty( const std::string& str );
bool	isCharLiteral( const std::string& str );
std::string	strWithoutWhitespace( std::string str );
bool	isIntLiteral( const std::string& str );
bool	isFloatLiteral( const std::string str );
bool	isDoubleLiteral( const std::string str );

#endif