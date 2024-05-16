/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:35:48 by yachen            #+#    #+#             */
/*   Updated: 2024/05/16 13:46:20 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

using std::cout;
using std::endl;

void	printContainerValue( std::deque<int> container )
{
	for(std::deque<int>::iterator it = container.begin(); it != container.end(); it++)
		std::cout << BLUE << *it << ' ';
	std::cout << '\n' << RESET;
}

int	main()
{
	cout << YELLOW << "-----------------------------\n" << RESET;
	unsigned int nMax = 10;
	cout << "n = " << nMax << ", create a Span sp\n";
	Span	sp( nMax );
	cout << "Add elements to sp: \n";
	try
	{
		sp.addLotNumber( 7 );
	}
	catch(std::out_of_range& e)
	{
		cout << RED << "Error: " << e.what() << '\n';
	}
	printContainerValue( sp.getMonSpan() );
	
	cout << YELLOW << "-----------------------------\n" << RESET;
	cout << "Create a sp copy, print it's elements :\n";
	Span	spCopy(sp);
	printContainerValue( spCopy.getMonSpan() );
	
	cout << YELLOW << "-----------------------------\n" << RESET;
	cout << "Creat a otherSp : otherSp = sp\n";
	Span	otherSp( 2 );
	otherSp = sp;	
	cout << "print it's elements : \n";
	printContainerValue( otherSp.getMonSpan() );
	
	cout << YELLOW << "-----------------------------\n" << RESET;
	try
	{
		cout << "Find shorted span in sp : " << sp.shortedSpan() << '\n';
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