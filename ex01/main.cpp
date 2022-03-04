#include "Bureaucrat.hpp"

int main()
{
	// Bureaucrat	b("Bob", 1);
	// Bureaucrat	b2;
	// b2=b;
	// std::cout << b2 << std::endl;
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