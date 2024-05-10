/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/10 18:11:54 by yachen           ###   ########.fr       */
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
		std::cout << "\nCreating bureacrate..." << std::endl;
		Bureaucrate	Sunny( "Sunny", 5 );
		std::cout << "Display bureaucrate's in formations" << std::endl;
		std::cout << Sunny << std::endl;
		std::cout << YELLOW << "----------------------------------------" << RESET << std::endl;
		std::cout << "Creating tree differents forms..." << std::endl;
		ShrubberyCreationForm	form1( "Home" );
		RobotomyRequestForm	form2( "Robot" );
		PresidentialPardonForm	form3( "somebody" );
		PresidentialPardonForm	form4( "form4" );
		std::cout << YELLOW << "----------------------------------------" << RESET << std::endl;
		std::cout << "Try to sign all forms : " << std::endl;
		Sunny.signForm( form1 );
		Sunny.signForm( form2 ); 
		Sunny.signForm( form3 );
		std::cout << YELLOW << "----------------------------------------" << RESET << std::endl;
		std::cout << "Try to execute all forms : " << std::endl;
		Sunny.executeForm( form1 );
		Sunny.executeForm( form2 );
		Sunny.executeForm( form3 );
		// std::cout << "Decrement bureaucrate's grade : " << std::endl;
		// Sunny.decrementeGrade();
		// std::cout << "Execute with grade lower than required execution grade : " << std::endl;
		// Sunny.executeForm( form3 );
		std::cout << YELLOW << "----------------------------------------" << RESET << std::endl;
		std::cout << "Try to execute forms without signing forms : " << std::endl;
		Sunny.executeForm( form4 );
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