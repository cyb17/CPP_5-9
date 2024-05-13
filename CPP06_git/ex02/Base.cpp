/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:10:50 by yachen            #+#    #+#             */
/*   Updated: 2024/05/13 15:46:51 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "color.h"

Base::~Base()
{
	std::cout << MAGENTA << "Base: Default destructor called\n" << RESET;
}

Base*	generate()
{
	srand(time(NULL));
	int	nb = rand() % 3;
	switch (nb)
	{
		case 0:
			std::cout << CYAN << "object A\n" << RESET;
			return new A;
		case 1:
			std::cout << CYAN << "object B\n" << RESET;
			return new B;
		case 2:
			std::cout << CYAN << "object C\n" << RESET;
			return new C;
	}
	return NULL;
}

void	identify( Base* p )
{
	std::cout << "Identify object type by pointer\n";
	if (dynamic_cast<A*>(p) != NULL)
        std::cout << BLUE << "Actual type: A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
        std::cout << BLUE << "Actual type: B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << BLUE << "Actual type: C" << RESET << std::endl;
	else
        std::cout << BLUE << "Unknown type" << RESET << std::endl;
}

void	identify( Base& p )
{
	std::cout << "Identify object type by reference\n";
	try
	{
		if (&dynamic_cast<A&>(p) != NULL)
       		std::cout << BLUE << "Actual type: A" << RESET << std::endl;
	}
	catch (...)
	{
		try
		{
			if (&dynamic_cast<B&>(p) != NULL)
				std::cout << BLUE << "Actual type: B" << RESET << std::endl;
		}
		catch (...)
		{
			try
			{
				if (&dynamic_cast<C&>(p) != NULL)
					std::cout << BLUE << "Actual type: C" << RESET << std::endl;
			}
			catch (...)
			{
        		std::cout << BLUE << "Unknown type" << RESET << std::endl;
			}	
		}
	}	
}
