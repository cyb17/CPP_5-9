/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/10 17:43:52 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"
#include "Form.hpp"

int	main( void )
{		
	try
	{
		std::cout << "\nCreating bureaucrate..." << std::endl;
		Bureaucrate	Sunny( "Sunny", 1 );
		std::cout << "Display bureaucrate's informations :" << std::endl;
		std::cout << Sunny << std::endl;
		std::cout << YELLOW << "------------------------------------" << RESET << std::endl;

		std::cout << "Creating form..." << std::endl;
		Form	form1( "form1", 1, 1);
		std::cout << "Display form's informations :" << std::endl;
		std::cout << form1 << std::endl;
		std::cout << YELLOW << "------------------------------------" << RESET << std::endl;

		// std::cout << "Create form with invalide grade" << std::endl;
		// Form	form2( "form2", 167, 1);
		// Form	form3( "form3", 1, -1);
		// std::cout << YELLOW << "------------------------------------" << RESET << std::endl;

		std::cout << "Create form's copy to teste copy constructor" << std::endl;
		Form	copy( form1 );
		std::cout << "Display informations :" << std::endl;
		std::cout << copy << std::endl;
		std::cout << YELLOW << "------------------------------------" << RESET << std::endl;

		std::cout << "Bureaucrate try to signe form :" << std::endl;
		Sunny.signForm( form1 );
		std::cout << "Teste besigned() function : " << std::endl;
		form1.beSigned( Sunny );
		std::cout << "Display form's informations :" << std::endl;
		std::cout << form1 << std::endl;
		std::cout << YELLOW << "------------------------------------" << RESET << std::endl;

		std::cout << "Decrement bureaucrate's grade :" << std::endl;
		Sunny.decrementeGrade();
		std::cout << "Display bureaucrate's informations :" << std::endl;
		std::cout << Sunny << std::endl;
		std::cout << "Bureaucrate try to signe form :" << std::endl;
		Sunny.signForm( form1 );
		std::cout << YELLOW << "------------------------------------" << RESET << std::endl;
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (Bureaucrate::GradeTooHighException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	catch (Bureaucrate::GradeTooLowException& e)
	{
		std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << "End of program" << std::endl;
	
	return 0;
}