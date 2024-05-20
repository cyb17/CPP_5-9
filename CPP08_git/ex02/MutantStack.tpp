/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:37:37 by yachen            #+#    #+#             */
/*   Updated: 2024/05/20 14:25:47 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include <stack>
#include <deque>

template<typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	public:
	
		MutantStack() : std::stack<T, Container>() {}
		MutantStack( const MutantStack& other ) : std::stack<T, Container>( other ) {}
		MutantStack&	operator=( const MutantStack& other )
		{
			if( this != &other )
				std::stack<T, Container>::operator=( other );
			return *this;
		}
		virtual ~MutantStack() {}

		typedef typename Container::iterator iterator;
		
		iterator	begin() { return this->c.begin(); } 
		iterator	end() { return this->c.end(); }

		typedef typename Container::const_iterator const_iterator;
		
		const_iterator	begin() const { return this->c.begin(); }
		const_iterator	end() const { return this->c.end(); }

		typedef typename Container::reverse_iterator reverse_iterator;

		reverse_iterator	rbegin() { return this->c.rbegin(); }
		reverse_iterator	rend() { return this->c.rend(); }

		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		const_reverse_iterator	rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator	rend() const { return this->c.rend(); }
};

#endif