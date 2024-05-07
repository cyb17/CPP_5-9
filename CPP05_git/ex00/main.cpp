/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/07 15:37:01 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

int	main( void )
{	
	Bureaucrate	Bob( "Bob", 151 );
	std::cout << Bob << std::endl;
	
	Bureaucrate	Sam( Bob );
	std::cout << Sam << std::endl;
	
	Bureaucrate	Alex( "Alex", 150 );
	Alex.decrementeGrade();
	std::cout << Alex << std::endl;

	Bureaucrate	Sunny( "Sunny", 6 );
	std::cout << Sunny << std::endl;
	
	std::cout << "End of program" << std::endl;
	
	return 0;
}