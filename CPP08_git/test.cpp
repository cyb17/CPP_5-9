/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:24:32 by yachen            #+#    #+#             */
/*   Updated: 2024/05/14 17:05:00 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include "ex00/easyfind.hpp"

class exceptionTeste : public std::exception
{
	private:
	
		const std::string errMsg;
	
	public:
		exceptionTeste( const std::string errMsg ) : errMsg( errMsg ) {}
		const char* what() const throw() { return errMsg.c_str(); }
};

void throwException( bool flag )
{
	if (flag == true)
		throw exceptionTeste( "exception throwed." );	
}


int main()
{
	try
	{
		throwException( true );
	}
	catch (exceptionTeste& e)
	{
		std::cout << e.what() << "\n";
	}

	std::vector<int> v = { 1, 2, 3, 3, 4, 5 };
	std::cout << easyfind(v, 3) << "\n";
	return 0;
}