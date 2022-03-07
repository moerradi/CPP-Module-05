#include "Intern.hpp"
const fnPtr Intern::_forms[3] = {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentialPardonForm}; 

Intern::Intern(void) {
	return ;
}

Intern::Intern(Intern const &src) {
	*this = src;
	return ;
}

Intern::~Intern(void) {
	return ;
}

Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return (*this);
}

const char *Intern::FormNotFoundException::what() const throw() {
	return ("Form not found");
}

Form *Intern::makePresidentialPardonForm(std::string target) const {
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeRobotomyForm(std::string target) const {
	return (new RobotomyRequestForm(target));
}

Form *Intern::makeShrubberyForm(std::string target) const {
	return (new ShrubberyCreationForm(target));
}

Form *Intern::makeForm(std::string form, std::string target) const {
	Form *ret = NULL;
	const std::string Forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (ret == NULL && i < 3) {
		if (Forms[i] == form)
			ret = (this->*_forms[i])(target);
		i++;
	}
	if (ret == NULL)
		throw FormNotFoundException();
	return (ret);
}