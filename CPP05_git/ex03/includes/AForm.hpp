/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <yachen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:12:16 by yachen            #+#    #+#             */
/*   Updated: 2024/03/20 11:14:59 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

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

class	Bureaucrate;

class	AForm
{
	private:

		const std::string	name;
		const std::string	target;
		bool				signStatus;
		const int			reqSignGrade;
		const int			reqExeGrade;

	public:

		AForm( const std::string nm, const std::string target, int signGrade, int exeGrade);
		AForm( const AForm& other );
		AForm&	operator = ( const AForm& other );
		virtual ~AForm();

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

		virtual const std::string	getName() const;
		virtual const std::string	getTarget() const;
		virtual bool				getSignStatus() const;
		virtual int					getReqSignGrade() const;
		virtual int					getReqExeGrade() const;
		virtual void				beSigned( Bureaucrate& ref );
		virtual	void				execute( const Bureaucrate& ref ) const = 0;
};

std::ostream&	operator<<( std::ostream& os, const AForm& obj );

#endif