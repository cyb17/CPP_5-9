/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:07:39 by yachen            #+#    #+#             */
/*   Updated: 2024/05/06 12:08:41 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class	Base
{
	public:

		virtual ~Base();
};

Base*	generate( void );
void	identify( Base* p );
void	identify( Base& p );

#endif