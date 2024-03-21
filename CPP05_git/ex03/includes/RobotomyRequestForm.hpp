/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:47:14 by yachen            #+#    #+#             */
/*   Updated: 2024/03/21 13:55:40 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include <iostream>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrate.hpp"

class	RobotomyRequestForm : public AForm
{
	public:

		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( const RobotomyRequestForm& other );
		RobotomyRequestForm&	operator = ( const RobotomyRequestForm& other );
		~RobotomyRequestForm();
		
		void	execute( const Bureaucrate& ref ) const;
};

#endif