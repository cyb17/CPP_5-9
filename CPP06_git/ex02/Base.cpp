/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:10:50 by yachen            #+#    #+#             */
/*   Updated: 2024/05/03 17:18:28 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "color.h"

Base::Base()
{
	std::cout << BLUE << "Base: Default constructor called\n" << RESET;
}

Base::~Base()
{
	std::cout << MAGENTA << "Base: Default destructor called\n" << RESET;
}

Base*	generate()
{
	int	nb = rand() % 3;

	switch (nb)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void	identify( Base* p )
{
	if (dynamic_cast<A*>(p) != NULL)
        std::cout << "Type: A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "Type: C" << std::endl;
	else
        std::cout << "Unknown type" << std::endl;
}

void	identify( Base& p )
{
	try
	{
		dynamic_cast<A&>(p);
        std::cout << "Type: A" << std::endl;
	}
	catch (const std::bad_cast&)
	{
		try
		{
			dynamic_cast<B&>(p);
        	std::cout << "Type: B" << std::endl;
		}
		catch (const std::bad_cast&)
		{
			try
			{
				dynamic_cast<C&>(p);
		        std::cout << "Type: C" << std::endl;
			}
			catch (const std::bad_cast&)
			{
        		std::cout << "Unknown type" << std::endl;
			}	
		}
	}	
}
