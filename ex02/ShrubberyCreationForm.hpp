#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);

		virtual ~ShrubberyCreationForm();

		void		execute(Bureaucrat const & executor) const;
	
	private:
		std::string _target;
};

#endif