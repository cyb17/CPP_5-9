/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:31:45 by yachen            #+#    #+#             */
/*   Updated: 2024/05/03 12:03:43 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include "../color.h"

class	Data
{
	private:

		int		i;
		char	c;

	public:

		Data( int i, char c );
		Data( const Data& other );
		Data&	operator= ( const Data& other );
		~Data();
		
		int	getI() const;
		char	getC() const;
};

#endif