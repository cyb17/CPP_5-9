/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/03/19 11:52:50 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

int	main( void )
{
	try
	{
		Bureaucrate	Bob( "Bob", 5 );
		Bureaucrate	Sam( "Sam", -1 );
		Bureaucrate	Alex( "Alex", 150 );

		Alex.decrementeGrade();
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}