#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern;	
typedef Form *(Intern::*fnPtr)(std::string) const;
class Intern {
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern &operator=(Intern const &rhs);

		Form	*makeForm(std::string form, std::string target) const;

		class FormNotFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		Form	*makeShrubberyForm(std::string target) const;
		Form	*makeRobotomyForm(std::string target) const;
		Form	*makePresidentialPardonForm(std::string target) const;
		
		static const fnPtr	_forms[3];	
};
// typedef Form (Intern::*fnPtr)(std::string);
#endif