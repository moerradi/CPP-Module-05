#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"
class Bureaucrat;
class Form {
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & src);

		Form & operator=(Form const & rhs);
		virtual ~Form();

		std::string		getName() const;
		bool			getSigned() const;
		int				getSignGrade() const;
		int				getExecGrade() const;

		void			beSigned(Bureaucrat const & b);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw();
		};
		
		class NotSignedException : public std::exception {
			public:
				virtual const char * what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int					_signGrade;
		int					_execGrade;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif