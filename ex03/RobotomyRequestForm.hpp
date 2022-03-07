#ifndef __RobotomyRequestForm_HPP__
#define __RobotomyRequestForm_HPP__

#include "Form.hpp"

class RobotomyRequestForm : public Form {
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);

		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

		virtual ~RobotomyRequestForm();

		void			execute(Bureaucrat const & executor) const;
	private:
		std::string _target;

};

#endif