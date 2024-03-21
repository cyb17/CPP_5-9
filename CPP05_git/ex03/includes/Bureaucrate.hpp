/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrate.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:22:02 by yachen            #+#    #+#             */
/*   Updated: 2024/03/21 10:39:58 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

#define RESET "\e[0m"
#define RED "\e[91m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define MAGENTA "\e[35m"
#define CYAN "\e[36m"
#define WHITE "\e[37m"

#include <iostream>
#include <exception>
#include <string>

class	AForm;

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
			private:
				const std::string	errMsg;
			public:
				GradeTooHighException( const std::string msg ) throw();
				~GradeTooHighException() throw();
				virtual const char* what() const throw();
		};
		
		class	GradeTooLowException : public std::exception
		{
			private:
				const std::string	errMsg;
			public:
				GradeTooLowException( const std::string msg ) throw();
				~GradeTooLowException() throw();
				virtual const char* what() const throw();
		};

		const std::string	getName() const;
		int					getGrade() const;
		void				incrementeGrade();
		void				decrementeGrade();
		void				signForm( AForm& ref );
		void				executeForm(const AForm& form);


};

std::ostream&	operator<<( std::ostream& os, const Bureaucrate& obj );

#endif