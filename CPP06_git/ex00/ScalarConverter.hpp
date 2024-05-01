/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:01:24 by yachen            #+#    #+#             */
/*   Updated: 2024/05/01 15:45:04 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include "../color.h"

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter( const ScalarConverter& other );
		ScalarConverter&	operator= ( const ScalarConverter& other );
				
	public:
	
		~ScalarConverter();
		static void Convert( std::string str );
};

bool	IsEmpty( const std::string& str );
bool	IsCharLiteral( const std::string& str );
std::string	StrWithoutWhitespace( std::string str );
bool	IsIntLiteral( const std::string& str );
bool	IsFloatLiteral( const std::string str );
bool	IsDoubleLiteral( const std::string str );

#endif