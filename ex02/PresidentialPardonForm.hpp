#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);

		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

		virtual ~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
	private:
		std::string _target;
};

#endif
