/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/03/20 10:29:49 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"
#include "Form.hpp"

int	main( void )
{	
	// try
	// {
	// 	Bureaucrate	Bob( "Bob", 5 );
	// 	std::cout << Bob << std::endl;
		
	// 	Bureaucrate	Sam( Bob );
	// 	std::cout << Sam << std::endl;
		
	// 	Bureaucrate	Alex( "Alex", 150 );
	// 	Alex.decrementeGrade();
	// 	std::cout << Alex << std::endl;

	// }
	// catch (Bureaucrate::GradeTooHighException& e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	// catch (Bureaucrate::GradeTooLowException& e)
	// {
	// 	std::cout << "Exception: " << e.what() << std::endl;
	// }
	
	Bureaucrate	Sunny( "Sunny", 1 );
	std::cout << Sunny << std::endl;
		
	try
	{
		Form	form1( "form1", 1, 1);
		std::cout << form1 << std::endl;
		form1.beSigned( Sunny );
		Sunny.signForm( form1 );
		std::cout << form1 << std::endl;
		
		Form	copy( form1 );
		std::cout << copy << std::endl;
		
		// Form	form2( "form2", -1, 1);
		// Form	form2( "form2", 151, 1);
		Form	form2( "form2", 5, 1);
		std::cout << form2 << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << "End of program" << std::endl;
	
	return 0;
}