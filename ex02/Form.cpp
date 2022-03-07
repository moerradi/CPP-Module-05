#include "Form.hpp"

// define functions in Form.hpp
Form::Form() : _name("")
{
	_signed = false;
	_signGrade = 150;
	_execGrade = 150;
	return ;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name)
{
	if (signGrade > 150)
		throw Form::GradeTooHighException();
	if (signGrade < 1)
		throw Form::GradeTooLowException();
	_signed = false;
	_signGrade = signGrade;
	_execGrade = execGrade;
	return ;
}

Form::Form(Form const & src) : _name(src._name)
{
	*this = src;
	return ;
}

Form & Form::operator=(Form const & rhs)
{
	this->_signed = rhs._signed;
	this->_signGrade = rhs._signGrade;
	this->_execGrade = rhs._execGrade;
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

bool	Form::getSigned() const
{
	return _signed;
}

int	Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecGrade() const
{
	return _execGrade;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form " << rhs.getName() << " is ";
	o << (rhs.getSigned() ? "signed" : "not signed");
	o << " and has a sign grade of " << rhs.getSignGrade() << " and an exec grade of " << rhs.getExecGrade() << ".";
	return o;
}

Form::~Form()
{
	return ;
}

void	Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	_signed = true;
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade is too low.";
}

const char* Form::NotSignedException::what() const throw()
{
	return "Form: Form is not signed.";
}