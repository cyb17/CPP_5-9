/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/08 13:28:14 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrate.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main( void )
{	
	
	try
	{
		Bureaucrate	Sunny( "Sunny", 25 );
		std::cout << Sunny << std::endl;
	
		ShrubberyCreationForm	form1( "Home" );
		RobotomyRequestForm	form2( "Robot" );
		PresidentialPardonForm	form3( "somebody" );
		Sunny.signForm( form1 );
		Sunny.signForm( form2 );
		Sunny.signForm( form3 );

		Sunny.executeForm( form1 );
		Sunny.executeForm( form2 );
		Sunny.executeForm( form3 );

	}
	catch (Bureaucrate::GradeTooHighException& e)
    {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    catch (Bureaucrate::GradeTooLowException& e)
    {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
	catch (AForm::GradeTooHighException& e)
    {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    catch (AForm::GradeTooLowException& e)
    {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
	
	std::cout << "End of program" << std::endl;

	return 0;
}