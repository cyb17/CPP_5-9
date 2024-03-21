/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:00:27 by yachen            #+#    #+#             */
/*   Updated: 2024/03/21 13:55:46 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include <iostream>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrate.hpp"

class	PresidentialPardonForm : public AForm
{
	public:

		PresidentialPardonForm( const std::string target );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		PresidentialPardonForm&	operator = ( const PresidentialPardonForm& other );
		~PresidentialPardonForm();
		
		void	execute( const Bureaucrate& ref ) const;
};

#endif