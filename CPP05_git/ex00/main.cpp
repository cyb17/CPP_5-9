/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/03/19 15:08:07 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

int	main( void )
{	
	try
	{
		Bureaucrate	Bob( "Bob", 5 );
		std::cout << Bob << std::endl;
		
		Bureaucrate	Sam( Bob );
		std::cout << Sam << std::endl;
		
		Bureaucrate	Alex( "Alex", 150 );
		Alex.decrementeGrade();
		std::cout << Alex << std::endl;

	}
	catch (Bureaucrate::GradeTooHighException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	catch (Bureaucrate::GradeTooLowException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	Bureaucrate	Sunny( "Sunny", 6 );
	std::cout << Sunny << std::endl;
	
	std::cout << "End of program" << std::endl;
	
	return 0;
}