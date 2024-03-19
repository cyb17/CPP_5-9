/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:22:02 by yachen            #+#    #+#             */
/*   Updated: 2024/03/19 12:23:10 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>

class	Bureaucrate
{
	private:
	
		const std::string	name;
		int					grade;

	public:

		Bureaucrate( const std::string nm, int gd );
		Bureaucrate( const Bureaucrate& other );
		Bureaucrate&	operator = ( const Bureaucrate& other );
		~Bureaucrate();

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		}
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		}

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementeGrade();
		void				decrementeGrade();


};

std::ostream&	operator<<( std::ostream& os, const Bureaucrate& obj );

#endif