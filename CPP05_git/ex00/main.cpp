/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/08 12:30:54 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"

int	main( void )
{	
	try
	{
		Bureaucrate	Bob( "Bob", 1 );
		std::cout << Bob << std::endl;
		
		Bureaucrate	Sam( Bob );
		std::cout << Sam << std::endl;
		
		Bureaucrate	Alex( "Alex", 150 );
		Alex.decrementeGrade();
		std::cout << Alex << std::endl;

	}
	catch (Bureaucrate::GradeTooHighException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (Bureaucrate::GradeTooLowException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	Bureaucrate	Sunny( "Sunny", 6 );
	std::cout << Sunny << std::endl;
	
	std::cout << "End of program" << std::endl;
	
	return 0;
}