/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/10 18:15:47 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrate.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int	main( void )
{	
	Bureaucrate	B("B", 1);
	Intern	intern;
	AForm*	tmp;
	
	tmp = intern.makeForm( "PresidentialPardonForm", "Target" );
	//tmp = intern.makeForm( "Unknown", "Target" );
	if (tmp)
	{
		B.signForm( *tmp );
		B.executeForm( *tmp );
	}
	std::cout << "End of program" << std::endl;
	return 0;
}