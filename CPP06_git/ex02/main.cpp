/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:43:52 by yachen            #+#    #+#             */
/*   Updated: 2024/05/06 13:29:59 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int	main( void )
{
	std::cout << "Generate a random objet\n";
	Base*	p1 = generate();
	std::cout << "Give it to a reference\n";
	Base&	rp1 = *p1;
	
	identify( p1 );
	identify( rp1 );
	
	delete(p1);
	return 0;
}