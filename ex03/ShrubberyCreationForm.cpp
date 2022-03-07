#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", 145, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 145, 137)
{
	this->_target = target;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
{
	*this = src;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw Form::NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	std::ofstream	file(this->_target + "_shrubbery");
	file << "          &&& &&  & &&\n";
	file << "      && &\\&\\|& ()|/ @, &&\n";
	file << "      &\\/(/&/&||/& /_/)_&/_&\n";
	file << "   &() &\\&|()|/&\\ '%' & ()\n";
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	file << "&&   && & &| &| /& & % ()& /&&\n";
	file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	file << "     &&     \\|||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "       , -=-~  .-^- _\n";
	file << "moe           `\n";
		file << "          &&& &&  & &&\n";
	file << "      && &\\&\\|& ()|/ @, &&\n";
	file << "      &\\/(/&/&||/& /_/)_&/_&\n";
	file << "   &() &\\&|()|/&\\ '%' & ()\n";
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	file << "&&   && & &| &| /& & % ()& /&&\n";
	file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	file << "     &&     \\|||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "       , -=-~  .-^- _\n";
	file << "moe           `\n";
	file << "          &&& &&  & &&\n";
	file << "      && &\\&\\|& ()|/ @, &&\n";
	file << "      &\\/(/&/&||/& /_/)_&/_&\n";
	file << "   &() &\\&|()|/&\\ '%' & ()\n";
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
	file << "&&   && & &| &| /& & % ()& /&&\n";
	file << " ()&_---()&\\&\\|&&-&&--%---()~\n";
	file << "     &&     \\|||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "             |||\n";
	file << "       , -=-~  .-^- _\n";
	file << "moe           `\n";
	file.close();
	return ;
}