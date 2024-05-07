/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/07 16:31:04 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrate.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main( void )
{	
	Bureaucrate	Sunny( "Sunny", 150 );
	std::cout << Sunny << std::endl;
	
	ShrubberyCreationForm	form1( "Home" );
	Sunny.executeForm( form1 );
	
	Bureaucrate	copieSunny( Sunny );
	std::cout << copieSunny << std::endl;
	std::cout << YELLOW << "-----------------------------------------------------------------\n";

	Bureaucrate	Robert( "Robert", 1 );
	std::cout << Robert << std::endl;
	
	RobotomyRequestForm	form2( "Robot" );
	Robert.executeForm( form2 );
	
	std::cout << YELLOW << "-----------------------------------------------------------------\n";
	
	Bureaucrate	Somebody( "Somebody", 1 );
	std::cout << Somebody << std::endl;
	
	PresidentialPardonForm	PresidentialPardonForm( "somebody" );
	Somebody.executeForm( PresidentialPardonForm );
	
	std::cout << "End of program" << std::endl;
	std::cout << YELLOW << "-----------------------------------------------------------------\n";

	return 0;
}