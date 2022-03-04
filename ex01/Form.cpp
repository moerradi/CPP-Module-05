#include "Form.hpp"

// define functions in Form.hpp
Form::Form() : _name(""), _signed(false), _signGrade(0), _execGrade(0)
{
	return ;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > 150)
		throw Form::GradeTooHighException();
	if (signGrade < 1)
		throw Form::GradeTooLowException();
	return ;
}

Form::Form(Form const & src) : _name(src._name), _signed(src._signed), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	return ;
}

Form & Form::operator=(Form const & rhs)
{
	this->_signed = rhs._signed;
	this->_signGrade = rhs._signGrade;
	this->_execGrade = rhs._execGrade;
	return *this;
}