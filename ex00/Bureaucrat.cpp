#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat::Bureaucrat(void) : _name(""){
	std::cout << "Bureaucrat : Default constructor called" << std::endl;
	_grade = 150;
	return ;
}

Bureaucrat::Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	std::cout << "Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name) {
	std::cout << "Copy constructor called" << std::endl;
	_grade = src._grade;
	return ;
}

Bureaucrat::Bureaucrat::~Bureaucrat(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::Bureaucrat::operator=(Bureaucrat const &rhs) {
	std::cout << "operator= called" << std::endl;
	_grade = rhs._grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}

std::string Bureaucrat::getName(void) const {
	return (_name);
}

int Bureaucrat::getGrade(void) const {
	return (_grade);
}

void Bureaucrat::incrementGrade(void) {
	if (_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	return ;
}

void Bureaucrat::decrementGrade(void) {
	if (_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	return ;
}

