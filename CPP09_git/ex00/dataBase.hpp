/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataBase.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:41:13 by yachen            #+#    #+#             */
/*   Updated: 2024/05/27 18:01:10 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BASE_HPP
#define DATA_BASE_HPP

#include <fstream>

class	dataBase
{
	private:
	
		std::ifstream	ifs;
		
	public:

		dataBase();
		dataBase( const dataBase& other );
		~dataBase();
		
		dataBase&	operator=( const dataBase& other );

		void	checkFileContent();
		
		bool	isValidDate();
		bool	isValidPrice();
		bool	isValidValue();
};


#endif