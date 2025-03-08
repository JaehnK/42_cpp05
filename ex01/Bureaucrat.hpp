#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class	Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
		
		Bureaucrat();
		void	setGrade(unsigned int grade);

	public:
		Bureaucrat(const std::string& name, unsigned int grade);
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat		&operator=(const Bureaucrat &rhs);
		~Bureaucrat();
	
		// getter	
		std::string		getName(void) const;
		unsigned int	getGrade(void) const;

		// funcs
		void			incrementGrade(void);
		void			decrementGrade(void);
		void			signForm(Form &f);

		// exceptions
		class	GradeTooHighException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				const char* what(void) const throw();
		};

};
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bu);

#endif
