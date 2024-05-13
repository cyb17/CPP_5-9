/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:54:26 by yachen            #+#    #+#             */
/*   Updated: 2024/05/13 14:55:49 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "color.h"
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:

		Serializer();
		Serializer( const Serializer& other );
		Serializer&	operator= ( const Serializer& other );
				
	public:
	
		~Serializer();
		static uintptr_t* serialize( Data* ptr );
		static Data* deserialize( uintptr_t* raw );
};

#endif