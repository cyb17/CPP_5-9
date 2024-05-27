/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:58:10 by yachen            #+#    #+#             */
/*   Updated: 2024/05/27 11:13:46 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
#include <iterator>
#include "MutantStack.hpp"

using std::cout;
using std::endl;

int	main()
{
	cout << "Create MutantStack objet ms: " << endl;
	MutantStack<int>	ms;
	cout << "add several int to ms: " << endl;
	for (int i = 0; i < 5; i++)
		ms.push(i);
	MutantStack<int>::reverse_iterator rit = ms.rbegin();
	while (rit != ms.rend())
	{
		cout << BLUE << *rit << ' ';
		rit++;
	}
	cout << RESET << endl;
	cout << "Is ms empty ? : " << ms.empty() << endl;
	return 0;
}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	std::cout << s.top() << std::endl;
// 	return 0;
// }

// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_front(5);
// 	mstack.push_front(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_front();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_front(3);
// 	mstack.push_front(5);
// 	mstack.push_front(737);
// 	//[...]
// 	mstack.push_front(0);
// 	std::list<int>::reverse_iterator it = mstack.rbegin();
// 	std::list<int>::reverse_iterator ite = mstack.rend();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	return 0;
// }
