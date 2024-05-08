/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/08 12:44:40 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"
#include "Form.hpp"

int	main( void )
{		
	try
	{
		Bureaucrate	Sunny( "Sunny", 1 );
		std::cout << Sunny << std::endl;

		Form	form1( "form1", 1, 1);
		std::cout << form1 << std::endl;
		Sunny.signForm( form1 );
		form1.beSigned( Sunny );
		std::cout << form1 << std::endl;
		Sunny.decrementeGrade();
		Sunny.signForm( form1 );

		Form	copy( form1 );
		std::cout << copy << std::endl;
		
		Form	form2( "form2", -1, 1);
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