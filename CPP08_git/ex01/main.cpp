/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:35:48 by yachen            #+#    #+#             */
/*   Updated: 2024/05/16 20:16:13 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

using std::cout;
using std::endl;

int	main()
{
	cout << YELLOW << "-----------------------------\n" << RESET;
	unsigned int nMax = 10000;
	cout << "n = " << nMax << ", create a Span sp\n";
	Span	sp( nMax );
	cout << "Add elements to sp: \n";
	try
	{
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(10);
		sp.addNumber(1000);
		sp.addNumber(16789);
		sp.addNumber(999);

		// sp.addLotNumber( 0 );
	}
	catch(std::out_of_range& e)
	{
		cout << RED << "Error: " << e.what() << '\n';
	}
	printContainerValue( sp.getMonSpan() );
	
	// cout << YELLOW << "-----------------------------\n" << RESET;
	// cout << "Create a sp copy, print it's elements :\n";
	// Span	spCopy(sp);
	// printContainerValue( spCopy.getMonSpan() );
	
	// cout << YELLOW << "-----------------------------\n" << RESET;
	// cout << "Creat a otherSp : otherSp = sp\n";
	// Span	otherSp( 2 );
	// otherSp = sp;	
	// cout << "print it's elements : \n";
	// printContainerValue( otherSp.getMonSpan() );
	
	cout << YELLOW << "-----------------------------\n" << RESET;
	try
	{
		cout << "Find shortest span in sp : " << sp.shortestSpan() << '\n';
	}
	catch(std::logic_error& e)
	{
		cout << RED << "Error: " << e.what() << '\n';
	}
	
	cout << YELLOW << "-----------------------------\n" << RESET;
	try
	{
		cout << "Find longest span in sp : " << sp.longestSpan() << '\n';
	}
	catch(std::logic_error& e)
	{
		cout << RED << "Error: " << e.what() << '\n';
	}
	
	return 0;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
	
// 	return 0;
// }