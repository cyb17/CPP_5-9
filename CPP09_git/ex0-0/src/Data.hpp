/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:07:33 by yachen            #+#    #+#             */
/*   Updated: 2024/05/24 10:47:08 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <map>

class	Data
{
	private:
	
		std::string	path;
		std::map<std::string, float>	content;

	public:

		Data();
		Data( const Data& other );
		~Data();
		
		Data&	operator=( const Data& other );

		void	readData() const;
}


#endif