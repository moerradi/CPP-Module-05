#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat::Bureaucrat(void) : _name(""){
	_grade = 150;
	return ;
}

Bureaucrat::Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name) {
	_grade = src._grade;
	return ;
}

Bureaucrat::Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat	&Bureaucrat::Bureaucrat::operator=(Bureaucrat const &rhs) {
	_grade = rhs._grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat: Grade too low");
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

void Bureaucrat::signForm(Form &f) {
	if (f.getSigned())
		std::cout << _name << " cannot sign " << f.getName() << " because it is already signed." << std::endl;
	else if (_grade > f.getSignGrade())
		std::cout << _name << " cannot sign " << f.getName() << " because his grade is too low." << std::endl;
	else {
		f.beSigned(*this);
		std::cout << _name << " signs " << f.getName() << "." << std::endl;
	}
	return ;
}

void Bureaucrat::executeForm(Form const &f) {
	if (!f.getSigned())
		std::cout << _name << " cannot execute " << f.getName() << " because it is not signed." << std::endl;
	else if (_grade > f.getExecGrade())
		std::cout << _name << " cannot execute " << f.getName() << " because his grade is too low." << std::endl;
	else {
		std::cout << _name << " executes " << f.getName() << "." << std::endl;
		f.execute(*this);
	}
	return ;
}