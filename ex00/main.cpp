#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Bob", 1);
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		b.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}