/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:36:49 by yachen            #+#    #+#             */
/*   Updated: 2024/05/10 17:33:15 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrate.hpp"
#include <string>
using std::cout;
using std::endl;

int	main( void )
{	
	std::string name;
	int			grade = 0;

	cout << "\nPlease, enter Bureaucrate's name : " << endl;
	std::cin >> name;
	while (name.empty())
	{
		cout << "Bureaucrate's name can not be empty, please enter again :" << endl;
		std::cin >> name;
	}
	cout << "Please, enter Bureaucrate's initial grade : " << endl;
	cout << "(only NUMBER is accepted otherwise the grade will be 0 by default.)" << endl;
	std::cin >> grade;
	try
	{
		cout << "\nCreating... " << endl;
		Bureaucrate	B( name, grade );
		cout << "Display informations: " << endl << B << endl;
		cout << YELLOW << "----------------------------------------" << RESET << endl;
		cout << "Create a copy of bureaucrate to teste copy constructor " << endl;
		Bureaucrate	copy( B );
		cout << "Display informations: " << endl << B << endl;
		cout << YELLOW << "----------------------------------------" << RESET << endl;		cout << "Try to increment " << name << "'s grade : " << endl;
		B.incrementeGrade();
		cout << "Display informations: " << endl << B << endl;
		cout << YELLOW << "----------------------------------------" << RESET << endl;
		cout << "Try to decrement " << name << "'s grade : " << endl;
		B.decrementeGrade();
		cout << "Display informations: " << endl << B << endl;
		cout << YELLOW << "----------------------------------------" << RESET << endl;
	}
	catch (Bureaucrate::GradeTooHighException& e)
	{
		cout << RED << "Exception: " << e.what() << RESET << endl;
	}
	catch (Bureaucrate::GradeTooLowException& e)
	{
		cout << RED << "Exception: " << e.what() << RESET << endl;
	}
	
	cout << "End of program" << endl;
	
	return 0;
}