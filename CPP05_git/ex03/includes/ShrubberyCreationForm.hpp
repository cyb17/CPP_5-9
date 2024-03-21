/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:12:28 by yachen            #+#    #+#             */
/*   Updated: 2024/03/21 13:55:32 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include <fstream>
#include <iostream>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrate.hpp"

class	ShrubberyCreationForm : public AForm
{	
	public:

		ShrubberyCreationForm( const std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
		ShrubberyCreationForm&	operator = ( const ShrubberyCreationForm& other );
		~ShrubberyCreationForm();
		
		void	execute( const Bureaucrate& ref ) const;
		void	formAction() const;
		void	writeAsciiTree( std::fstream& fs ) const;
};

#endif