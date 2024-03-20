/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:12:16 by yachen            #+#    #+#             */
/*   Updated: 2024/03/20 10:19:22 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class	Bureaucrate;

class	Form
{
	private:

		const std::string	name;
		bool				signStatus;
		const int			reqSignGrade;
		const int			reqExeGrade;

	public:

		Form( const std::string nm, int signGrade, int exeGrade);
		Form( const Form& other );
		Form&	operator = ( const Form& other );
		~Form();

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
		bool				getSignStatus() const;
		int					getReqSignGrade() const;
		int					getReqExeGrade() const;
		void				beSigned( Bureaucrate& ref );
};

std::ostream&	operator<<( std::ostream& os, const Form& obj );

#endif