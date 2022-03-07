#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern intern;
		Form *form;
		form = intern.makeForm("presidential pardon", "Bob");
		Bureaucrat b("simo", 1);
		b.signForm(*form);
		b.executeForm(*form);
		delete form;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}