/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:01:24 by yachen            #+#    #+#             */
/*   Updated: 2024/04/30 18:14:35 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP
#define CHAR 5
#define INT 6
#define FLOAT 7
#define DOUBLE 8
#define NONE 9


#include <string>
#include "../color.h"

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter( const ScalarConverter& other );
		ScalarConverter&	operator= ( const ScalarConverter& other );
		bool	IsEmpty( const std::string& str ) const;
		bool	IsCharLiteral( const std::string& str ) const;
		std::string	StrWithoutWhitespace( std::string str );
		bool	IsIntLiteral( const std::string& str ) const;
		bool	IsFloatLiteral( const std::string str ) const;
		bool	IsDoubleLiteral( const std::string str ) const;
		
	public:
	
		~ScalarConverter();
		static void Convert( std::string str );
};



#endif