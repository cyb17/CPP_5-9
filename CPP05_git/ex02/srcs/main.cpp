/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/03/21 12:07:45 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrate.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main( void )
{	
	Bureaucrate	Sunny( "Sunny", 2 );
	std::cout << Sunny << std::endl;
	
	ShrubberyCreationForm	Home( "Home" );
	Sunny.executeForm( Home );
	
	try
	{
		Bureaucrate	copieSunny( "copieSunny", 2 );
		std::cout << copieSunny << std::endl;
	}
	catch (Bureaucrate::GradeTooHighException& e)
    {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    catch (Bureaucrate::GradeTooLowException& e)
    {
            std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
	std::cout << YELLOW << "-----------------------------------------------------------------\n";

	Bureaucrate	Robert( "Robert", 150 );
	std::cout << Robert << std::endl;
	
	RobotomyRequestForm	Robot( "Robot" );
	Robert.executeForm( Robot );
	
	std::cout << YELLOW << "-----------------------------------------------------------------\n";
	
	Bureaucrate	Somebody( "Somebody", 1 );
	std::cout << Somebody << std::endl;
	
	PresidentialPardonForm	PresidentialPardonForm( "PresidentialPardonForm" );
	Somebody.executeForm( PresidentialPardonForm );
	
	std::cout << "End of program" << std::endl;

	return 0;
}