#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5)
{
	this->_target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
{
	*this = src;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
	return ;
}