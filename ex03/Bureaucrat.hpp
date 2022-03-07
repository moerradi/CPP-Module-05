#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>
#include "Form.hpp"
class Form;
class Bureaucrat {
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &rhs);
		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(Form &f);
		void executeForm(Form const &f);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string const _name;
		int _grade;
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
