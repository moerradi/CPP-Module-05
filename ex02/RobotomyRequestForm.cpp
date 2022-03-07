#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45)
{
	this->_target = target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
{
	*this = src;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	std::cout << "* Drilling noises *" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization failed" << std::endl;
	return ;
}