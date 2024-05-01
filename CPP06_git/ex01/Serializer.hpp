/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:54:26 by yachen            #+#    #+#             */
/*   Updated: 2024/05/01 15:59:51 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "../color.h"

class Serializer
{
	private:

		Serializer();
		Serializer( const Serializer& other );
		Serializer&	operator= ( const Serializer& other );
				
	public:
	
		~Serializer();
};
#endif